#include "HandShakeTask.h"
#include "TacheDuReception.h"
#include "IgssClient.h"
#include "TacheDuTransmission.h"

//!
//! \brief HandShakeTask::HandShakeTask
//! \param connexions
//!
HandShakeTask::HandShakeTask(qintptr ID,AlgorithmTestPlatform * algorithmTestPlatform){
    this->algorithmTestPlatform = algorithmTestPlatform;
    this->socketDescriptor = ID;
}

//!
//! \brief HandShakeTask::run
//!
void HandShakeTask::run(){



    socket = new QTcpSocket();

    //set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error (socket->error());
        return;
    }
    qDebug()<<"HandShakeTask Thread Start";
    connect(socket,SIGNAL(readyRead()),this,SLOT(readRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));

    exec();
}

//!
//! \brief HandShakeTask::readRead
//!
void HandShakeTask::readRead(){
    //get the information
    QByteArray Data = socket->readAll();

    qDebug()<<socketDescriptor<<"Data in: "<<Data;

    QString msg(Data);
    if(msg.contains("cciss")){

        QStringList msg_temp = msg.split(" ");
        qDebug()<<msg_temp;

        //!Every new connection will be run in a new created thread
        //!once a thread is not needed , it will be deleted later
        TacheDuReception *client1 = new TacheDuReception(socketDescriptor ,socket,algorithmTestPlatform);
        //connect(client1,SIGNAL(finished()),client1,SLOT(deleteLater()));
        client1->start();

        IgssClient* connectionToSend = new IgssClient();
        connectionToSend->start("172.20.35.141", 12345);


    }

}

//!
//! \brief HandShakeTask::disconnected
//!
void HandShakeTask::disconnected(){

    //this->algorithmTestPlatform->setSystemStatus(socketDescriptor+"Disconnected");

    qDebug()<<socketDescriptor<<" Disconnected";
    socket->deleteLater();
    exit(0);
}

//!
//! \brief HandShakeTask::~HandShakeTask
//!
HandShakeTask::~HandShakeTask()
{

}

