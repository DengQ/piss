#include "IgssClient.h"


IgssClient::IgssClient(QObject *parent): QObject(parent){
    connect(&igssclient,SIGNAL(connected()),this,SLOT(startTransfer()));
}

void IgssClient::start(QString address, quint16 port)
{
    QHostAddress addr(address);
    igssclient.connectToHost(addr,port);
}

void IgssClient::startTransfer()
{
    igssclient.write("piss");

    if(igssclient.waitForBytesWritten()){
        TacheDuTransmission *igssToServer = new TacheDuTransmission();
        igssToServer->start();
    }
}

IgssClient::~IgssClient()
{
    igssclient.close();
}
