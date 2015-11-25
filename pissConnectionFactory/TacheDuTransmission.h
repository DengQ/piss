#ifndef TACHEDUTRANSMISSION_H
#define TACHEDUTRANSMISSION_H

#include <QThread>
#include "AlgorithmTestPlatform.h"
#include "IgssClient.h"

#include <QTcpSocket>
#include <Qtcore>
#include <QtNetwork/qnetworkconfiguration.h>
#include <QList>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QDebug>
#include <QSettings>

class TacheDuTransmission : public QThread
{
    Q_OBJECT
public:
    TacheDuTransmission();
    ~TacheDuTransmission();
    void run();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // TACHEDUTRANSMISSION_H
