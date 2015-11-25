#include "TacheDuTransmission.h"
#include "IgssClient.h"

TacheDuTransmission::TacheDuTransmission()
{

}

TacheDuTransmission::~TacheDuTransmission()
{

}

void TacheDuTransmission::run(){

    while(1){
        qDebug()<<"TacheDuTransmission Thread start!";
        msleep(500);
    }


  //  IgssClient igssclient;
   // igssclient.start("172.20.35.141",8888);
}

