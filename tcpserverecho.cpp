#include "tcpserverecho.h"

TcpServerEcho::TcpServerEcho(const QHostAddress &address, quint16 port, QObject* parent):QTcpServer(parent)
{
    listen(address, port);
}

TcpServerEcho::~TcpServerEcho()
{
//    qDebug() << __FUNCTION__;
}

void TcpServerEcho::incomingConnection(int socketDescriptor)
{
    UserConnectedThread* thread = new UserConnectedThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
