#ifndef TACHDURECEPTION_H
#define TACHDURECEPTION_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "AlgorithmTestPlatform.h"

class TacheDuReception : public QThread{

    Q_OBJECT
public:
    explicit TacheDuReception(qintptr socketDescriptor, QTcpSocket *socket,AlgorithmTestPlatform * algorithmTestPlatform);
    ~TacheDuReception();

    void run();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
    AlgorithmTestPlatform * algorithmTestPlatform;

};

#endif // TACHDURECEPTION_H
