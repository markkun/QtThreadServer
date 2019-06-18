#include "userconnectedthread.h"

UserConnectedThread::UserConnectedThread(int socketDescriptor, QObject* parent):QThread(parent), socketDesc(socketDescriptor)
{
}

UserConnectedThread::~UserConnectedThread()
{
//    qDebug() << __FUNCTION__;
}

void UserConnectedThread::run()
{
    QTcpSocket tcpSocket;

    if(!tcpSocket.setSocketDescriptor(socketDesc))
        return;

    QString info = QString("[%0:%1]").arg(tcpSocket.peerAddress().toString()).arg(tcpSocket.peerPort());
    qDebug() << info << " connected.";

    while (true)
    {
        if(tcpSocket.error() == QAbstractSocket::RemoteHostClosedError)
            break;

        if(tcpSocket.waitForReadyRead(0))
        {
            QByteArray data = tcpSocket.readAll();
            if(strncmp(data.toStdString().c_str(), "quit", 4) == 0)
                break;
            tcpSocket.write(data);
            tcpSocket.waitForBytesWritten();
        }
    }

    tcpSocket.close();
    qDebug() << info << " disconnected.";
}
