#ifndef IGSSSERVER_H
#define IGSSSERVER_H

#include <QThread>
#include <QSettings>
#include<QTcpServer>
#include<QTcpSocket>
#include<QObject>
#include<QString>
#include<QDebug>

#include <QtCore>
#include <QtNetwork/qnetworkconfiguration.h>
#include <QList>

QT_BEGIN_NAMESPACE
class QThread;
class QTcpServer;
class QNetworkSession;
class QNetworkConfigurationManager;
class QtNetwork;
class QTcpSocket;
QT_END_NAMESPACE

#include <stdlib.h>
#include <TacheDuReception.h>
#include "AlgorithmTestPlatform.h"



/**
 * @brief The IgssServer class
 *
 * Le class qui gère le channel de réception, par example: les images traités, les états du serveur,  etc.
 *
 */
class IgssServeur: public QTcpServer
{
    Q_OBJECT
public:
    explicit IgssServeur(AlgorithmTestPlatform * algorithmTestPlatform);
    ~IgssServeur();

    void startServer();

    void initVariable();
    void setConnections();

private:
    AlgorithmTestPlatform * algorithmTestPlatform;
    QTcpServer server;
    QTcpSocket *client;
//    QList<QTcpSocket*> connexions;
//    QList<QString> connexions;
    TacheDuReception* tacheDuReception;

public slots:
    void acceptConnection();
    void startRead();

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // IGSSSERVER_H
