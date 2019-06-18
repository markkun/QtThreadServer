#ifndef TCPSERVERECHO_H
#define TCPSERVERECHO_H

#include <QTcpServer>
#include "userconnectedthread.h"
#include <QHostAddress>

class TcpServerEcho : public QTcpServer
{
    Q_OBJECT

public:
    TcpServerEcho() = delete;
    TcpServerEcho(const QHostAddress &address = QHostAddress::Any, quint16 port = 0, QObject* parent = nullptr);
    virtual ~TcpServerEcho();

protected:
    void incomingConnection(int socketDescriptor);
};

#endif // TCPSERVERECHO_H
