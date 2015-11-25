#include "IgssServeur.h"
#include "HandShakeTask.h"
#include "IgssClient.h"

#include <stdlib.h>
#include <iostream>
#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

using namespace std;


//!------------------------------------------------------------------------
//!
//! \brief IgssServer::IgssServer
//!
IgssServeur::IgssServeur(AlgorithmTestPlatform * algorithmTestPlatform){
    this->algorithmTestPlatform = algorithmTestPlatform;
//    this->initVariable();
//    this->setConnections();
}


//!------------------------------------------------------------------------
//! \brief IgssServeur::startServer
//!
void IgssServeur::startServer(){
    int port=1234;

    if(!this->listen(QHostAddress::Any, port)){
        qDebug()<<"Could not start server";
    }else{
        qDebug()<<"Listening to port";
    }
}

//!------------------------------------------------------------------------
//!
//! \brief IgssServer::initVariable
//!
void IgssServeur::initVariable(){
}

//!------------------------------------------------------------------------
//! \brief IgssServeur::incomingConnection
//! \param socketDescriptor
//!
void IgssServeur::incomingConnection(qintptr socketDescriptor){

    //We have a new connection
    //this->algorithmTestPlatform->setSystemStatus(socketDescriptor+" Connectiong ...");
    qDebug() << socketDescriptor<<" Connectiong ...";

    //Every new connection will be run in a new created thread
    HandShakeTask *thread = new HandShakeTask(socketDescriptor ,algorithmTestPlatform);

    //once a thread is not needed , it will be deleted later
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

    thread->start();
}

//!------------------------------------------------------------------------
//!
//! \brief IgssServer::setConnections
//!
void IgssServeur::setConnections(){
    this->connect(&server, SIGNAL(newConnection()),this, SLOT(acceptConnection()));
}

//!------------------------------------------------------------------------
//!
//! \brief IgssServer::acceptConnection
//!
void IgssServeur::acceptConnection(){
//  connexions.append(server->nextPendingConnection());

  client = server.nextPendingConnection();

  connect(client,SIGNAL(readyRead()),this,SLOT(startRead()));
}

//!
//! \brief IgssServeur::startRead
//!
void IgssServeur::startRead(){
    char buffer[1024]={0};
    client->read(buffer,client->bytesAvailable());
//    connexions = buffer;
//    switch (connexions){

//    }

    cout<<buffer<<endl;
    client->close();
}

//!------------------------------------------------------------------------
//!
//! \brief IgssServer::~IgssServer
//!
IgssServeur::~IgssServeur(){

}
