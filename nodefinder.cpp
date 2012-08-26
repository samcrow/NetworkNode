#include "nodefinder.hpp"

const int NodeFinder::port = 2727;

/**
  Periodically sends out messages indicating the presence of this node
  and listens for messages indicating the presence of other nodes.

  Datagram format:
  quint16: unique node ID
  */
NodeFinder::NodeFinder(QObject *parent) :
    QObject(parent)
{

    //Assign the random ID
    int tempId = qrand();
    do {
        tempId = qrand();
    } while( tempId < 0 || tempId > 65535);
    id = tempId;

    socket = new QUdpSocket(this);
    socket->bind(port, QUdpSocket::ShareAddress);
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));

    timerId = startTimer(1000);
}


void NodeFinder::timerEvent(QTimerEvent *e) {
    if(e->timerId() == timerId) {
        broadcastMessage();
    }
}

void NodeFinder::broadcastMessage() {

    QByteArray message;
    QBuffer buffer(&message);
    buffer.open(QIODevice::WriteOnly); // This needs to be called. Otherwise all this won't work.
    QDataStream stream(&buffer);

    stream << id;

    if(message.size() > 512) {
        qWarning() << "Trying to send a datagram"
                   << message.size() << "bytes long. This, being larger than 512, may cause problems.";
    }

//    for(int i = 0, max = message.length(); i < max; i++) {
//        char value = message.at(i);
//        qDebug() << (int)value;
//    }
    socket->writeDatagram(message, QHostAddress::Broadcast, port);
}

void NodeFinder::read() {

    QByteArray input;
    input.resize(socket->pendingDatagramSize());

    QHostAddress senderAddress;

    socket->readDatagram(input.data(), input.size(), &senderAddress);
    QBuffer buffer(&input);
    buffer.open(QIODevice::ReadOnly);
    QDataStream stream(&buffer);

//    qDebug() << "Datagram from" << senderAddress.toString();

    quint16 foundId;
    stream >> foundId;

//    qDebug() << "This ID" << id << "Other ID" << foundId;

    //Only do anything if the node that sent this message wasn't this one
    if(foundId != id) {
        qDebug() << "Datagram from other node" << foundId << "at" << senderAddress.toString();
        emit foundPeer(senderAddress, foundId);
    }
    else {
//        qDebug() << "Datagram from this node. Ignoring.";
    }
}
