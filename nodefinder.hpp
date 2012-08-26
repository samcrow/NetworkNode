#ifndef NODEFINDER_HPP
#define NODEFINDER_HPP

#include <QObject>
#include <QDebug>
#include <QTimerEvent>
#include <QDataStream>
#include <QBuffer>
#include <QDateTime>
#include <QtNetwork/QUdpSocket>

/**
  This class manages finding other nodes on the network.
  Using a timer, it periodically sends out UDP packets letting
  other nodes know about this node.
  When it receives notice of a new node, it emits its foundPeer() signal.
  */
class NodeFinder : public QObject
{
    Q_OBJECT
public:
    explicit NodeFinder(QObject *parent = 0);

    static const int port;

protected:

    /**
      Random identifier for this node on the network.
      It must be unique among all computers connected to the network.
      The current implementation, as a 16-bit unsigned integer,
      only works for a network with up to 65,535 computers on it.
      Hopefully that won't be a problem.
      */
    quint16 id;

    int timerId;

    void timerEvent(QTimerEvent * e);

    QUdpSocket * socket;

private:

    void broadcastMessage();

signals:

    void foundPeer(QHostAddress peerAddress, int peerId);

public slots:

private slots:

    void read();

};

#endif // NODEFINDER_HPP
