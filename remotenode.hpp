#ifndef REMOTENODE_HPP
#define REMOTENODE_HPP

#include <QObject>

/**
  Manages a remote node in the network
  */
class RemoteNode : public QObject
{
    Q_OBJECT
public:
    explicit RemoteNode(QObject *parent = 0);

signals:

public slots:

};

#endif // REMOTENODE_HPP
