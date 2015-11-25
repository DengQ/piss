#include "GuidewareTrackingWindow.h"

GuidewareTrackingWindow::GuidewareTrackingWindow(QRect rect,
                                                 SystemDispatcher* systemDispatcher) : QWidget(){
    this->x = rect.x();
    this->y = rect.y();
    this->width = rect.width();
    this->height = rect.height();
    this->systemDispatcher = systemDispatcher;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);// | Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);
    this->initVariable();
    this->constructionIHM();
    this->setConnections();
    this->drawBackground();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::~GuidewareTrackingWindow
//!
GuidewareTrackingWindow::~GuidewareTrackingWindow(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::displayWindow
//!
void GuidewareTrackingWindow::displayWindow(){
    this->resize(this->width, this->height);
    this->move(this->x, this->y);
    this->show();
}

//!
//! \brief GuidewareTrackingWindow::initVariable
//!
void GuidewareTrackingWindow::initVariable(){
    this->caracterStyle = new QFont("Segoe UI", 8, QFont::AnyStyle, false);
    this->windowStyleSheet = "border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue";
}

//!
//! \brief GuidewareTrackingWindow::constructionIHM
//!
void GuidewareTrackingWindow::constructionIHM(){
    //!----------------------------------------------------------------------------------------------------
    //! name bar:display name of this window
    //!----------------------------------------------------------------------------------------------------
    this->nameBar = new QLabel();
    this->nameBar->setText("Guideware Tracking Window");
    this->nameBar->setFixedSize(width*0.20,height*0.04);
    this->nameBar->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gainsboro;border-bottom-width:1px solid gainsboro;border-right-width:1px solid gainsboro; border-radius: 0px;margin-top: 0ex;} ");
    this->nameBar->setFont(QFont("Segoe UI", 11, QFont::DemiBold, true));
    this->nameBar->setAlignment(Qt::AlignCenter);

    //!----------------------------------------------------------------------------------------------------
    //! vtk display bar:display name of VTKImage
    //!----------------------------------------------------------------------------------------------------
    this->vtkDisplayBar = new QWidget();
    this->vtkDisplayBar->setFixedSize(width*0.80,height*0.04);
    this->vtkDisplayBar->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gainsboro; border-bottom-width:1px solid gainsboro; border-radius: 0px;margin-top: 0ex;} ");

    //!----------------------------------------------------------------------------------------------------
    //! surgery information:including surgerID,patientName,surgeryDate
    //!----------------------------------------------------------------------------------------------------
    this->surgeryID = new QLabel();
    this->surgeryID = new QLabel("surgeryID:");
    this->surgeryID->setFont(*this->caracterStyle);
    this->surgeryID->setStyleSheet("border: 0px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    this->patientName = new QLabel();
    this->patientName = new QLabel("patientName:");
    this->patientName->setFont(*this->caracterStyle);
    this->patientName->setStyleSheet("border: 0px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    this->surgeryDate = new QLabel();
    this->surgeryDate = new QLabel("surgeryDate:");
    this->surgeryDate->setFont(*this->caracterStyle);
    this->surgeryDate->setStyleSheet("border: 0px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    this->surgeryIDLineEdit = new QLineEdit();
    this->surgeryIDLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    this->surgeryIDLineEdit->setReadOnly(true);
    this->surgeryIDLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");

    this->patientNameLineEdit = new QLineEdit();
    this->patientNameLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    this->patientNameLineEdit->setReadOnly(true);
    this->patientNameLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");

    this->surgeryDateLineEdit = new QLineEdit();
    this->surgeryDateLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    this->surgeryDateLineEdit->setReadOnly(true);
    this->surgeryDateLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");

    this->surgeryInformation = new QWidget();
    this->surgeryInformation->setFixedHeight(height*0.16);
    this->surgeryInformation->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gray; border-radius: 5px;margin-top: 1ex;} ");
    //this->surgeryInformation->setStyleSheet(this->windowStyleSheet);
    this->surgeryInformationLayout = new QGridLayout(this->surgeryInformation);
    this->surgeryInformationLayout->addWidget(surgeryID, 0, 0);
    this->surgeryInformationLayout->addWidget(surgeryIDLineEdit, 0, 1);
    this->surgeryInformationLayout->addWidget(patientName, 1, 0);
    this->surgeryInformationLayout->addWidget(patientNameLineEdit, 1, 1);
    this->surgeryInformationLayout->addWidget(surgeryDate, 2, 0);
    this->surgeryInformationLayout->addWidget(surgeryDateLineEdit, 2, 1);
    //this->surgeryInformationLayout->setMargin(0);
    //this->surgeryInformationLayout->setSpacing(0);

    //!----------------------------------------------------------------------------------------------------
    //! control button area
    //!----------------------------------------------------------------------------------------------------
    this->untitledButton1 = new QPushButton("X");
    this->untitledButton1->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton1->setStyleSheet("QPushButton{background-color:transparent; color: Aliceblue; border: 1px solid gray; border-radius: 5px;margin-top: 1ex;} ");
    this->untitledButton2 = new QPushButton("-");
    this->untitledButton2->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton2->setStyleSheet("background-color:transparent; color: Aliceblue; border: 1px solid gray; border-radius: 5px;margin-top: 1ex;");
    this->untitledButton3 = new QPushButton("-");
    this->untitledButton3->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton3->setStyleSheet("background-color:transparent; color: Aliceblue; border: 1px solid gray; border-radius: 5px;margin-top: 1ex; ");
    this->untitledButton4 = new QPushButton("^");
    this->untitledButton4->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton4->setStyleSheet("background-color:transparent; color: Aliceblue; border: 1px solid gray; border-radius: 5px;margin-top: 1ex; ");
    this->controlButtonArea = new QWidget();
    this->controlButtonArea->setFixedHeight(height*0.4);
    this->controlButtonArea->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gray; border-radius: 5px;margin-top: 1ex;} ");
    this->controlButtonAreaLayout = new QGridLayout(this->controlButtonArea);
    this->controlButtonAreaLayout->addWidget(this->untitledButton1, 0, 0);
    this->controlButtonAreaLayout->addWidget(this->untitledButton2, 0, 1);
    this->controlButtonAreaLayout->addWidget(this->untitledButton3, 0, 3);
    this->controlButtonAreaLayout->addWidget(this->untitledButton4, 0, 4);
    this->controlButtonAreaLayout->setMargin(0);
    this->controlButtonAreaLayout->setSpacing(0);




    //!----------------------------------------------------------------------------------------------------
    //! unknown area
    //!----------------------------------------------------------------------------------------------------
    this->unknownArea = new QWidget();
    this->unknownArea->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gray; border-radius: 5px;margin-top: 1ex;} ");

    //!----------------------------------------------------------------------------------------------------
    //!guideControlBoard:including guideControlBoard,controlButtonArea,unknownArea
    //!----------------------------------------------------------------------------------------------------
    this->guideControlBoard = new QWidget();
    this->guideControlBoard->setFixedWidth(width*0.2);
    this->guideControlBoard->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gainsboro; border-right-width:1px solid gainsboro; border-radius: 0px;margin-top: 0ex;} ");
    //this->guideControlBoard->setStyleSheet(this->windowStyleSheet);
    this->guideControlBoardLayout = new QVBoxLayout(this->guideControlBoard);
    this->guideControlBoardLayout->addWidget(this->surgeryInformation);
    this->guideControlBoardLayout->addWidget(this->controlButtonArea);
    this->guideControlBoardLayout->addWidget(this->unknownArea);
    this->guideControlBoardLayout->setMargin(0);
    this->guideControlBoardLayout->setSpacing(0);


    //!----------------------------------------------------------------------------------------------------
    //!primary display
    //!----------------------------------------------------------------------------------------------------
    this->realTimeDisplay = new QWidget();
    realTimeDisplay->setFixedSize(width*0.40,height*0.48);
    l_layout = new QHBoxLayout(realTimeDisplay);
    f_vtkwidget = new QVTKWidget();
    //f_vtkwidget->setStyleSheet("background-color:red");
    l_layout->addWidget(f_vtkwidget);

    //!----------------------------------------------------------------------------------------------------
    //!lastFrameWidget
    //!----------------------------------------------------------------------------------------------------
    this->lastFrameWidget = new QWidget();


    //!----------------------------------------------------------------------------------------------------
    //!guideware tracking display
    //!----------------------------------------------------------------------------------------------------
    this->guidewareTrackingDisplay = new QWidget();
    //guidewareTrackingDisplay->setFixedSize(width*0.40,height*0.80);
    r_layout = new QHBoxLayout(guidewareTrackingDisplay);
    videoWidget = new QVideoWidget;
    videoWidget->setStyleSheet("background-color:blue");
    r_layout->addWidget(videoWidget);

    //!----------------------------------------------------------------------------------------------------
    //!somethingElse
    //!----------------------------------------------------------------------------------------------------
    this->somethingElse = new QWidget();

    //!----------------------------------------------------------------------------------------------------
    //!vtkDisplayBoard:including primaryDisplay,guidewareTrackingDisplay
    //!----------------------------------------------------------------------------------------------------
    this->vtkDisplayBoard = new QWidget();
    this->vtkDisplayBoard->setStyleSheet("QWidget{background-color:transparent; color: Aliceblue; border: 0px solid gainsboro; border-radius: 0px;margin-top: 0ex;} ");
    this->vtkDisplayBoardLayout = new QGridLayout(this->vtkDisplayBoard);
    this->vtkDisplayBoardLayout->addWidget(realTimeDisplay, 0, 0);
    this->vtkDisplayBoardLayout->addWidget(lastFrameWidget, 0, 1);
    this->vtkDisplayBoardLayout->addWidget(guidewareTrackingDisplay, 1, 0);
    this->vtkDisplayBoardLayout->addWidget(somethingElse, 1, 1);
    this->vtkDisplayBoardLayout->setMargin(0);
    this->vtkDisplayBoardLayout->setSpacing(0);

    //!----------------------------------------------------------------------------------------------------
    //!main window
    //!----------------------------------------------------------------------------------------------------
    this->guidewareTrackingLayout = new QGridLayout(this);
    this->guidewareTrackingLayout->addWidget(this->nameBar, 0, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBar, 0, 1);
    this->guidewareTrackingLayout->addWidget(this->guideControlBoard, 1, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBoard, 1, 1);
    this->guidewareTrackingLayout->setMargin(0);
    this->guidewareTrackingLayout->setSpacing(0);

}

//!
//! \brief GuidewareTrackingWindow::setConnections
//!
void GuidewareTrackingWindow::setConnections(){
    this->connect(untitledButton1, SIGNAL(clicked()), this, SLOT(closeSystem()));
    this->connect(untitledButton2, SIGNAL(clicked()), this, SLOT(insertVideoplay()));
    this->connect(untitledButton3, SIGNAL(clicked()), this, SLOT(screenShot()));
    //this->connect(untitledButton4, SIGNAL(clicked()), this, SLOT(VTKDisplay()));
}

//!
//! \brief GuidewareTrackingWindow::closeSystem
//!
void GuidewareTrackingWindow::closeSystem(){
    this->close();
}

void GuidewareTrackingWindow::VTKDisplay(){

    vtkSmartPointer<vtkDICOMImageReader> reader =
            vtkSmartPointer<vtkDICOMImageReader>::New();
    reader->SetFileName("E:\\MarchingMan\\MarchingMan01.dcm");
    reader->Update();

    // Visualize
    vtkSmartPointer<vtkImageViewer2> imageViewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer->SetInputConnection(reader->GetOutputPort());
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();

    this->f_vtkwidget->SetRenderWindow(renderWindowInteractor->GetRenderWindow());
    renderWindowInteractor->SetRenderWindow(renderWindowInteractor->GetRenderWindow());
    renderWindowInteractor->Start();
    this->f_vtkwidget->show();
}

void GuidewareTrackingWindow::screenShot(){
    QPixmap pixmap;
    QPixmap pix;
    pix = pixmap.grabWidget(videoWidget, 0, 0, -1, -1);
    if(pix.isNull())
        {
            QMessageBox::information(this,"error","grab Screen failed",QMessageBox::Ok);
        }
        else
        {
            if(pix.save( "E:\\1.bmp", "BMP" )==false)
            {
                QMessageBox::information(this,"right","save error",QMessageBox::Ok);
            }
            else
                QMessageBox::information(this,"Grab","bitmap saved as E:\\1.bmp",QMessageBox::Ok);
        }

}

void GuidewareTrackingWindow::insertVideoplay(){
//    vtkSmartPointer<vtkDICOMImageReader> reader =
//            vtkSmartPointer<vtkDICOMImageReader>::New();
//    reader->SetFileName("E:\\MarchingMan\\MarchingMan01.dcm");
//    reader->Update();

//    // Visualize
//    vtkSmartPointer<vtkImageViewer2> imageViewer =
//            vtkSmartPointer<vtkImageViewer2>::New();
//    imageViewer->SetInputConnection(reader->GetOutputPort());
//    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
//            vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    imageViewer->SetupInteractor(renderWindowInteractor);
//    imageViewer->Render();
//    imageViewer->GetRenderer()->ResetCamera();
//    imageViewer->Render();

//    this->f_vtkwidget->SetRenderWindow(renderWindowInteractor->GetRenderWindow());
//    renderWindowInteractor->SetRenderWindow(renderWindowInteractor->GetRenderWindow());
//    renderWindowInteractor->Start();
//    this->f_vtkwidget->show();
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("E:\\LIU_XINKUN-3-3.avi"));
    player->setVideoOutput(videoWidget);
    videoWidget->show();
    player->play();
}


//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::drawBackground
//!
void GuidewareTrackingWindow::drawBackground(){
    pixmap = new QPixmap(":/images/background_darkBlue.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(this->width, this->height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

    this->setPalette(p);
    this->setMask(pixmap->mask());
}

void GuidewareTrackingWindow::testVtkwidget(){

}
