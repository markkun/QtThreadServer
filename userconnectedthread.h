#ifndef USERCONNECTEDTHREAD_H
#define USERCONNECTEDTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include "tcpserverecho.h"
#include <QDebug>

class UserConnectedThread : public QThread
{
    Q_OBJECT

public:
    UserConnectedThread(int socketDescriptor, QObject* parent = nullptr);
    virtual ~UserConnectedThread();
    void run() override;

private:
    int socketDesc;
};

#endif // USERCONNECTEDTHREAD_H
