#ifndef HANDSHAKETASK_H
#define HANDSHAKETASK_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "AlgorithmTestPlatform.h"

//!------------------------------------------------------------------------
//!
//! \brief The HandShakeTask class
//!
class HandShakeTask : public QThread
{
    Q_OBJECT

public:

    explicit HandShakeTask(qintptr ID,AlgorithmTestPlatform * algorithmTestPlatform);
    ~HandShakeTask();

    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;

    AlgorithmTestPlatform * algorithmTestPlatform;
//    QList<QTcpSocket*> connexions;
};

#endif // HANDSHAKETASK_H
