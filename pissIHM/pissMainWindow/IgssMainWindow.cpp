#include "IgssMainWindow.h"
#include "vtkImageData.h"


IgssMainWindow::IgssMainWindow(SystemDispatcher* dispatcher): QWidget(){

    this->systemDispatcher = dispatcher;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    //this->setStyleSheet("background-color:rgb(58,89,92)");
    this->drawBackground();
}

//!---------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::getAlgorithmTestPlatform
//! \return
//!
AlgorithmTestPlatform* IgssMainWindow::getAlgorithmTestPlatform(){
    return this->algorithmTestPlatform;
}

//!---------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::constructIHM
//!
void IgssMainWindow::constructIHM(){

    //!------------------------------------------------------------------------------------------
    //! configurationBoard:
    //!------------------------------------------------------------------------------------------
    configurationBoard = new QWidget();
    configurationBoard->setFixedWidth(this->primary_screen_width*0.13);

    //!------------------------------------------------------------------------------------------
    //! system information board: a place where all information about pa    //qDebug()<<patient->MraImageReadComplete;tient, doctor and replays
    //! in the system will be displayed here
    //!------------------------------------------------------------------------------------------
    patientsWidget = new PatientsWidget(this->systemDispatcher,
                                        this->algorithmTestPlatform,
                                        this->surgeryPlanWindow,
                                        this->patientInformationWidget,
                                        this->guidewareTrackingWindow,
                                        this->surgeryTimer,
                                        this->englishCaracterStyle,
                                        this->primary_screen_width,
                                        this->primary_screen_height);

    replaysWidget = new ReplaysWidget();
    surgerySystemWidget = new SurgerySystemWidget();

    systemInformationBoard = new QTabWidget();
    systemInformationBoard->setStyleSheet(this->systemInformationBoardStyleSheet);

    systemInformationBoard->insertTab(0, patientsWidget, "Patients");
    systemInformationBoard->insertTab(1, surgerySystemWidget, "System");
    systemInformationBoard->insertTab(2, replaysWidget, "History");
    systemInformationBoard->setFont(QFont("Times",12,QFont::Bold, false));

    systemInformationBoardWidget = new QWidget();
    systemInformationBoardWidgetLayout = new QHBoxLayout(systemInformationBoardWidget);
    systemInformationBoardWidgetLayout->addWidget(systemInformationBoard);
    systemInformationBoardWidgetLayout->setSpacing(0);
    systemInformationBoardWidgetLayout->setMargin(0);

    //!------------------------------------------------------------------------------------------
    //! controlBoard:
    //!------------------------------------------------------------------------------------------
    closeButton = new QPushButton();
    closeButton->setIcon(QIcon(":/images/close.png"));
    closeButton->setIconSize(QSize(this->primary_screen_width*0.018,this->primary_screen_width*0.018));
    closeButton->setStyleSheet("background-color:transparent");

    closeButton->setFixedSize(this->primary_screen_width*0.023, this->primary_screen_width*0.023);

    this->pickInformationBoardButton = new QPushButton();
    this->pickInformationBoardButton->setFixedSize(30,30);
    this->pickInformationBoardButton->setIcon(QIcon(":/images/fileList.png"));
    this->pickInformationBoardButton->setStyleSheet("background-color:transparent");

    controlAreaItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    controlArea = new QWidget();
    controlAreaLayout = new QVBoxLayout(controlArea);
    controlAreaLayout->addWidget(pickInformationBoardButton);
    controlAreaLayout->addItem(controlAreaItem);
    controlAreaLayout->setSpacing(0);
    controlAreaLayout->setMargin(0);

    controlBoard = new QWidget();
    controlBoard->setFixedWidth(this->primary_screen_width*0.024);
    controlBoardLayout = new QVBoxLayout(controlBoard);
    controlBoardLayout->addWidget(closeButton);
    controlBoardLayout->addWidget(controlArea);
    controlBoardLayout->setSpacing(0);
    controlBoardLayout->setMargin(0);

    //!----------------------------------------------------------------------------------------------------
    //! main platform
    //!----------------------------------------------------------------------------------------------------
    mainPlatform = new QWidget();
    mainPlatformLayout = new QHBoxLayout(mainPlatform);
    mainPlatformLayout->addWidget(configurationBoard);
    mainPlatformLayout->addWidget(systemInformationBoardWidget);
    mainPlatformLayout->addWidget(controlBoard);
    mainPlatformLayout->setSpacing(0);
    mainPlatformLayout->setMargin(0);

    //!----------------------------------------------------------------------------------------------------
    //! main window
    //!----------------------------------------------------------------------------------------------------
    igssMainWindowLayout =  new QVBoxLayout(this);
    igssMainWindowLayout->addWidget(mainPlatform);
    igssMainWindowLayout->addWidget(algorithmTestPlatform);
    igssMainWindowLayout->setSpacing(2);
    igssMainWindowLayout->setMargin(0);
}

//!---------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::findPatientExisted
//!
void IgssMainWindow::findPatientExisted(){
   patientsWidget->findPatientExisted();
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief AnalyserMainWindow::drawBackground
//!
void IgssMainWindow::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(this->primary_screen_width, this->primary_screen_height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!---------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::initVariable
//!
void IgssMainWindow::initVariable(){

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);
    mouseLeftButtonPressed = false;
    pickInformationBoardButtonIsClicked = false;

    desktop = QApplication::desktop();
    screen_count = desktop->screenCount();
    primary_screen = desktop->primaryScreen();
    screen = new Screen[screen_count];

    for(unsigned char i = 0; i < screen_count; i++){
        screen[i].screenIndex = primary_screen + i;
        screen[i].rect = desktop->screenGeometry(primary_screen + i);
        qDebug()<<screen[i].rect.width();
    }

    primary_screen_width = screen[0].rect.width();
    primary_screen_height = screen[0].rect.height();
    //this->resize(primary_screen_width,primary_screen_height);

    flag = 0;

    this->systemInformationBoardStyleSheet =
            "QTabWidget::pane{border: 0px;top: 0em;border-top-width: 0px;border-style: solid;border-color: aliceblue;}"
            "QTabBar::tab{ width:"+ QString::number(primary_screen_width*0.875 * 0.31) + ";height:" + QString::number(primary_screen_height*0.03) + ";margin-left: 0.5; margin-right: 0.5;border: 1px solid gray;border-top-left-radius: 4px; border-top-right-radius: 4px;padding: 2px 6px 2px 6px;}"
            "QTabBar::tab:hover{border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue}"
            "QTabBar::tab:!selected {border-color: aliceblue; margin-left: 0px;margin-right: 0px;color: rgb(190,190,190);margin-top: 0px;}"
            "QTabBar::tab:selected {border-color: aliceblue; margin-left: 0px;margin-right: 0px; margin-top: 0px; background-color: transparent;color: white; border-width: 1px;}"
            "QTabBar::tab::bottom {border-bottom-left-radius: 4px; border-bottom-right-radius: 4px; border-top-left-radius: 0px;border-top-right-radius: 0px;padding: 2px 6px 2px 6px;}";

    this->englishCaracterStyle = new QFont("Times",8,QFont::AnyStyle, false);

    //!----------------------------------------------------------------------------------------------------
    //! status bar area
    //!----------------------------------------------------------------------------------------------------
    algorithmTestPlatform = new AlgorithmTestPlatform(this->systemDispatcher,
                                                      this->primary_screen_width,
                                                      this->primary_screen_height);

    this->patientInformationWidget = new PatientInformationWidget();

    this->surgeryTimer = new QTime();

    this->surgeryPlanWindow = new SurgeryPlanWindow(screen[1].rect,  this->surgeryTimer, this->systemDispatcher, this->algorithmTestPlatform);

    this->guidewareTrackingWindow = new GuidewareTrackingWindow(screen[2].rect, this->systemDispatcher);

}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setConnectios
//!
void IgssMainWindow::setConnections(){
    this->connect(closeButton, SIGNAL(clicked()), this, SLOT(closeSystem()));
    this->connect(pickInformationBoardButton,SIGNAL(clicked()), this, SLOT(pickInformationBoardButtonClicked()));
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::initVisualizationComponents
//!
void IgssMainWindow::initVisualizationComponents(){
    volumeMapper = vtkVolumeRayCastMapper::New();
    compositeFunction = vtkVolumeRayCastCompositeFunction::New();
    volume = vtkVolume::New();
    renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::display
//!
void IgssMainWindow::display(){
    this->showFullScreen();
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::setSystemDispatecher
//! \param dispatcher
//!
void IgssMainWindow::setSystemDispatecher(SystemDispatcher* dispatcher){
    this->systemDispatcher = dispatcher;
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::displayMraImage
//! \param input
//!
void IgssMainWindow::displayMraImage(vtkImageData* input){
    this->volumeMapper->SetVolumeRayCastFunction(compositeFunction);
    this->volumeMapper->SetInputData(input);
    this->volume->SetMapper(volumeMapper);
    this->renderer->AddVolume(volume);
    this->renderer->SetBackground(0.1, 0.21, 0.31);
    this->renderWindow->AddRenderer(renderer);
    this->renderer->ResetCamera();
    this->mraImageDisplayWindow->SetRenderWindow(this->renderWindow);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief Widget::readImageFileFrom
//! \param path
//!
void IgssMainWindow::readImageFileFrom(QString path){
    mhdImagePath = path;
    mraImage = new IgssImage();
    mhdFileReader = new MRAFileReader();
    mhdFileReader->doParseMHDFileToIgssImage(mhdImagePath ,mraImage);

}

//!----------------------------------------------------------------------------------------
//!
//! \brief Widget::readImageFromVtkConvert
//!
void IgssMainWindow::readImageFromVtkConvert()
{
    igssImage = new IgssImage();
    vtkImage = vtkImageData::New();
    vtkImage->SetDimensions(25,25,25);
    vtkImage->SetSpacing(1.0,1.0,1.0);
    vtkImage->SetOrigin(0.0,0.0,0.0);
    vtkImage->AllocateScalars(VTK_UNSIGNED_SHORT,1);
    unsigned short *ptr = (unsigned short*)vtkImage->GetScalarPointer();
    for(long i=0;i<25*25*25;i++)
    {
        *ptr++ = i;
    }
    igssVtkImageConverter = new IgssVtkImageConverter();
    this->pickInformationBoardButton->setIcon(QIcon(":/images/fileList-pressed.png"));
    igssVtkImageConverter->VtkToIgss(vtkImage,igssImage);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::closeSystem
//!
void IgssMainWindow::closeSystem(){

    qDebug()<<this->patientsWidget->testX()<<this->patientsWidget->testY();

    if (!(QMessageBox::information(this,tr("Igss Control View"),tr("Do you really want to log out Igss Control View?"),tr("Yes"),tr("No")))){
    this->close();
    this->guidewareTrackingWindow->close();
    this->surgeryPlanWindow->close();
    }
}

//!
//! \brief IgssMainWindow::pickInformationBoardButtonClicked
//!
void IgssMainWindow::pickInformationBoardButtonClicked(){
    if(!pickInformationBoardButtonIsClicked){
        this->pickInformationBoardButton->setIcon(QIcon(":/images/fileList-pressed.png"));
        this->pickInformationBoardButton->setStyleSheet("background-color:transparent");
        this->configurationBoard->close();
        //this->patientsWidget_width = primary_screen_width*0.976;
    }
    else{
        this->pickInformationBoardButton->setIcon(QIcon(":/images/fileList.png"));
        this->pickInformationBoardButton->setStyleSheet("background-color:transparent");
        this->configurationBoard->show();
    }
    pickInformationBoardButtonIsClicked = !pickInformationBoardButtonIsClicked;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::mouseMoveEvent
//! \param event
//!
void IgssMainWindow::mouseMoveEvent(QMouseEvent *event){
    if(mouseLeftButtonPressed == true){
        mouseMovingPosition = event->globalPos();
        this->move(this->pos() + mouseMovingPosition - mousePosition);
        mousePosition = mouseMovingPosition;
    }
    event->ignore();
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::mousePressEvent
//! \param event
//!
void IgssMainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
       if (!((event->y() < 5) || (event->x() <5))){
           mousePosition = event->globalPos();
           mouseLeftButtonPressed = true;
       }
    }
    event->ignore();
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief IgssMainWindow::mouseReleaseEvent
//! \param event
//!
void IgssMainWindow::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        mouseLeftButtonPressed = false;
    }
    event->ignore();
}
