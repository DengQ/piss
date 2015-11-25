#include "AlgorithmTestPlatform.h"

AlgorithmTestPlatform::AlgorithmTestPlatform(SystemDispatcher* dispatcher,
                                             int appWidth,
                                             int appHeight)
{
    this->dispatcher = dispatcher;
    this->appWidth = appWidth;
    this->appHeight = appHeight;
    this->setFixedHeight(this->appHeight*0.18);
    this->initVariable();
    this->constructIHM();
    this->setConnections();
}

//!
//! \brief AlgorithmTestPlatform::initVariable
//!
void AlgorithmTestPlatform::initVariable(){

    this->labelStyleSheet = "border: 1px solid aliceBlue;border-radius: 10px;padding: 2 2px;background-color: transparent; color: AliceBlue";
    this->progressBarStyleSheet = "QProgressBar {border: 1px solid aliceBlue;border-radius: 5px;}"
                                  "QProgressBar::chunk {background-color: #05B8CC;width: 10px;}";
    this->caracterStyle = new QFont("Times",9,QFont::AnyStyle, false);
}

//!
//!runmTestPlatform::constructIHM
//!
void AlgorithmTestPlatform::constructIHM(){

    this->cpuLabel = new QLabel("CPU");
    this->cpuLabel->setFixedSize(appWidth*0.022,appHeight*0.02);
    this->cpuLabel->setFont(*this->caracterStyle);
    this->cpuLabel->setStyleSheet(this->labelStyleSheet);
    this->cpuLabel->setAlignment(Qt::AlignCenter);
    this->ramLabel = new QLabel("RAM");
    this->ramLabel->setFixedSize(appWidth*0.022,appHeight*0.02);
    this->ramLabel->setFont(*this->caracterStyle);
    this->ramLabel->setStyleSheet(this->labelStyleSheet);
    this->ramLabel->setAlignment(Qt::AlignCenter);
    this->diskLable = new QLabel("Disk");
    this->diskLable->setFixedSize(appWidth*0.022,appHeight*0.02);
    this->diskLable->setFont(*this->caracterStyle);
    this->diskLable->setStyleSheet(this->labelStyleSheet);
    this->diskLable->setAlignment(Qt::AlignCenter);
    this->netLable = new QLabel("Net");
    this->netLable->setFixedSize(appWidth*0.022,appHeight*0.02);
    this->netLable->setFont(*this->caracterStyle);
    this->netLable->setStyleSheet(this->labelStyleSheet);
    this->netLable->setAlignment(Qt::AlignCenter);

    this->cpuProgressBar = new QProgressBar();
    this->cpuProgressBar->setOrientation(Qt::Horizontal);
    this->cpuProgressBar->setFixedHeight(appHeight*0.01);
    this->cpuProgressBar->setStyleSheet(this->progressBarStyleSheet);
    this->cpuProgressBar->setMinimum(0);
    this->cpuProgressBar->setMaximum(100);
    this->ramProgressBar = new QProgressBar();
    this->ramProgressBar->setOrientation(Qt::Horizontal);
    this->ramProgressBar->setFixedHeight(appHeight*0.01);
    this->ramProgressBar->setStyleSheet(this->progressBarStyleSheet);
    this->ramProgressBar->setMinimum(0);
    this->ramProgressBar->setMaximum(100);
    this->diskProgressBar = new QProgressBar();
    this->diskProgressBar->setOrientation(Qt::Horizontal);
    this->diskProgressBar->setFixedHeight(appHeight*0.01);
    this->diskProgressBar->setStyleSheet(this->progressBarStyleSheet);
    this->diskProgressBar->setMinimum(0);
    this->diskProgressBar->setMaximum(100);
    this->netProgressBar = new QProgressBar();
    this->netProgressBar->setOrientation(Qt::Horizontal);
    this->netProgressBar->setFixedHeight(appHeight*0.01);
    this->netProgressBar->setStyleSheet(this->progressBarStyleSheet);
    this->netProgressBar->setMinimum(0);
    this->netProgressBar->setMaximum(100);

    this->systemUsageStatusWidget = new QLabel();
    this->systemUsageStatusWidget->setStyleSheet("border-radius: 0px;background-color: transparent; color: AliceBlue");
    this->systemUsageStatusWidget->setFixedWidth(this->appWidth*0.13);
    this->systemUsageStatusLayout = new QGridLayout(this->systemUsageStatusWidget);
    this->systemUsageStatusLayout->addWidget(this->cpuLabel, 0, 0);
    this->systemUsageStatusLayout->addWidget(this->ramLabel, 1, 0);
    this->systemUsageStatusLayout->addWidget(this->diskLable, 2, 0);
    this->systemUsageStatusLayout->addWidget(this->netLable, 3, 0);

    this->systemUsageStatusLayout->addWidget(this->cpuProgressBar, 0, 1);
    this->systemUsageStatusLayout->addWidget(this->ramProgressBar, 1 , 1);
    this->systemUsageStatusLayout->addWidget(this->diskProgressBar, 2 , 1);
    this->systemUsageStatusLayout->addWidget(this->netProgressBar, 3 , 1);

    systemStatus = new QTextEdit();
    systemStatus->setFont(*this->caracterStyle);
    systemStatus->setStyleSheet("border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    systemCommand = new QLineEdit();
    systemCommand->setFont(*this->caracterStyle);
    systemCommand->setStyleSheet("border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    terminalWindow = new QWidget();
    terminalWindowLayout = new QVBoxLayout(terminalWindow);
    terminalWindowLayout->addWidget(systemStatus);
    terminalWindowLayout->addWidget(systemCommand);
    terminalWindowLayout->setSpacing(0);
    terminalWindowLayout->setMargin(0);

    platformLayout = new QHBoxLayout(this);
    platformLayout->addWidget(systemUsageStatusWidget);
    platformLayout->addWidget(terminalWindow);
    platformLayout->setSpacing(0);
    platformLayout->setMargin(0);
}

void AlgorithmTestPlatform::setConnections(){
    this->connect(systemCommand,SIGNAL(returnPressed()),this,SLOT(doParseCommand()));
}

void AlgorithmTestPlatform::setSystemStatus(QString status){
    this->systemStatus->setText(status);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief AlgorithmTestPlatform::doParseCommand
//!
void AlgorithmTestPlatform::doParseCommand(){

    QString cmd = systemCommand->text();
    setSystemStatus(cmd);
    QString msg;

    if(cmd.contains("vef")){
        if(cmd.contains("mri")){
            QStringList temp = cmd.split(" mri ");
            int id = temp[1].toInt(0,10);
            msg = this->dispatcher->doImageProcessingByMethodType(id, 3, "vef");
        }
        else{
            //!do 2d vessel enhancement
        }
        this->setSystemStatus(msg);
    }
    else if(cmd.contains("check")){
        if(cmd.contains("mri")){
            if(cmd.contains("states")){
                this->getPatientsStatus();
            }
        }
    }
}

//!----------------------------------------------------------------------------------------
//!doParseCommand
//! \brief AlgorithmTestPlatform::getPatientsStatus
//!
void AlgorithmTestPlatform::getPatientsStatus(){
    QStringList s = this->dispatcher->getPatientsStatus();
    QString info = "";
    for(int i = 0; i < s.length(); i++){
        info += s[i]+"\n";
    }
    this->setSystemStatus(info);
}

