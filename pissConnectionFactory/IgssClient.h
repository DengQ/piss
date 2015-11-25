#ifndef IGSSCLIENT_H
#define IGSSCLIENT_H

#include <QThread>
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
#include "TacheDuTransmission.h"


class IgssClient:public QObject
{
    Q_OBJECT
public:
    IgssClient(QObject* parent = 0);
    ~IgssClient();
    void start(QString address, quint16 port);

public slots:
    void startTransfer();

private:
    QTcpSocket igssclient;
    qintptr socketDescription;
};

#endif // IGSSCLIENT_H
