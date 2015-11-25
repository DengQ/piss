#include "TacheDuReception.h"
#include "IgssClient.h"

TacheDuReception::TacheDuReception(qintptr socketDescriptor, QTcpSocket *socket,AlgorithmTestPlatform * algorithmTestPlatform)/*:QThread(parent)*/
{
    this->algorithmTestPlatform = algorithmTestPlatform;
    this->socket = socket;
    this->socketDescriptor = socketDescriptor;
}

//!
//! \brief TacheDuReception::run
//!
void TacheDuReception::run(){
    while(true){
        //this->algorithmTestPlatform->setSystemStatus("ThreadDuReceptionClient1 Thread Start");
        qDebug()<<socketDescriptor<<"ThreadDuReceptionClient1 Thread Start";
        //if(this->socket->read())

        msleep(500);
    }
}

//!
//! \brief TacheDuReception::~TacheDuReception
//!
TacheDuReception::~TacheDuReception()
{

}
