#include "IgssMainWindow.h"
#include "SystemDispatcher.h"
#include "SystemDataBase.h"
#include "IgssServeur.h"
#include "IgssClient.h"
#include "IgssConnectionDoctor.h"
#include <QApplication>
#include <QTimer>
#include <QThread>
#include "HandShakeTask.h"

int main(int argc, char *argv[]){    

    QApplication analyser(argc, argv);
    analyser.setOrganizationName("CAS - SIAT");
    analyser.setApplicationName("igss");
    analyser.setWindowIcon(QIcon(":/images/icon.png"));

    //! TODO: global timer to be defined....

    //! IHM System
    SystemDataBase*   database       = new SystemDataBase();
    SystemDispatcher* dispatcher     = new SystemDispatcher();
    IgssMainWindow*   igssMainWindow = new IgssMainWindow(dispatcher);
    ImageProcessingFactory *imageProcessingFactory = new ImageProcessingFactory();

    igssMainWindow->setSystemDispatecher(dispatcher);
    dispatcher->setSystemDataBase(database);
    dispatcher->setImageProcessingFactory(imageProcessingFactory);
    database->setImageProcessingFactory(imageProcessingFactory);
    igssMainWindow->findPatientExisted();

    //! lAN environnement initialization
    IgssServeur* connectionToReceive = new IgssServeur(igssMainWindow->getAlgorithmTestPlatform());
    connectionToReceive->startServer();

    //! IgssConnectionDoctor* networkDiagnosisTask = new IgssConnectionDoctor();

    igssMainWindow->display();

    return analyser.exec();

}
