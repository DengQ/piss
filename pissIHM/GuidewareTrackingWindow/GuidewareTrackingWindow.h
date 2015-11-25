#ifndef GUIDEWARETRACKINGWINDOW_H
#define GUIDEWARETRACKINGWINDOW_H

#include <Patient.h>
#include <SystemDispatcher.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QVTKWidget.h>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMessageBox>
#include <QLineEdit>
#include "CurveReformationWindow.h"

#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkImageCanvasSource2D.h>
//#include <vtkAVIWriter.h>

class GuidewareTrackingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GuidewareTrackingWindow(QRect rect,
                                     SystemDispatcher* systemDispatcher);
    ~GuidewareTrackingWindow();
    void initVariable();
    void displayWindow();
    void constructionIHM();
    void setConnections();
    void drawBackground();
    void testVtkwidget();


private:
    int x;
    int y;
    int width;
    int height;
    Patient* patientHandling;
    SystemDispatcher* systemDispatcher;

    QFont *caracterStyle;
    QString windowStyleSheet;

    QPixmap *pixmap;

    QGridLayout* guidewareTrackingLayout;
    QGridLayout* vtkDisplayBoardLayout;
    QVBoxLayout* guideControlBoardLayout;
    QGridLayout* surgeryInformationLayout;
    QGridLayout* controlButtonAreaLayout;

    QPushButton* untitledButton1;
    QPushButton* untitledButton2;
    QPushButton* untitledButton3;
    QPushButton* untitledButton4;

    QWidget* vtkDisplayBar;
    QWidget* guideControlBoard;
    QWidget* vtkDisplayBoard;
    QWidget* realTimeDisplay;
    QWidget* lastFrameWidget;
    QWidget* guidewareTrackingDisplay;
    QWidget* somethingElse;
    QWidget* surgeryInformation;
    QWidget* controlButtonArea;
    QWidget* unknownArea;

    QVTKWidget* f_vtkwidget;
    QVTKWidget* s_vtkwidget;
    QHBoxLayout* l_layout;
    QHBoxLayout* r_layout;

    QLabel* nameBar;
    QLabel* surgeryID;
    QLabel* patientName;
    QLabel* surgeryDate;

    QLineEdit* surgeryIDLineEdit;
    QLineEdit* patientNameLineEdit;
    QLineEdit* surgeryDateLineEdit;

    QMediaPlayer* player;
    QVideoWidget* videoWidget;

public slots:
    void closeSystem();
    void VTKDisplay();
    void screenShot();
    void insertVideoplay();
};

#endif // GUIDEWARETRACKINGWINDOW_H
