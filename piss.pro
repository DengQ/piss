#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T10:03:34
#
#-------------------------------------------------

QT       += multimedia network core gui multimediawidgets
#CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

unix:QMAKE_CXXFLAGS += -Wno-deprecated

TARGET = piss
TEMPLATE = app

## Define output directories
#DESTDIR = ../bin
#CUDA_OBJECTS_DIR = OBJECTS_DIR/../cuda

# This makes the .cu files appear in your project
#CUDA_SOURCES += \
#    vectorAdd.cu

INCLUDEPATH += pissSystemDataWare

INCLUDEPATH += pissIHM

INCLUDEPATH += pissConnectionFactory

INCLUDEPATH += pissIHM/CurveReformationWindow

INCLUDEPATH += pissIHM/GuiComponentLib

INCLUDEPATH += pissIHM/GuidewareTrackingWindow

INCLUDEPATH += pissIHM/SurgeryPlanWindow

INCLUDEPATH += pissIHM/pissMainWindow

INCLUDEPATH += pissDispatcher

INCLUDEPATH += pissDiskImageReaderFactory

INCLUDEPATH += pissImageProcessingMethods

INCLUDEPATH += pissImageProcessingMethods/igssGeneralLib

INCLUDEPATH += pissImageProcessingMethods/igssMathLib

INCLUDEPATH += pissImageProcessingMethods/igssSegmentationLib

RESOURCES = imageresources.qrc

SOURCES +=  main.cpp\
            pissDispatcher/SystemDispatcher.cpp \
            pissSystemDataWare/SystemDataBase.cpp \
            pissSystemDataWare/igssImage.cpp \
            pissImageProcessingMethods/igssGeneralLib/igssVtkImageConverter.cpp \
            pissSystemDataWare/CenterLinePoint.cpp \
            pissIHM/pissMainWindow/igssMainWindow.cpp \
            pissSystemDataWare/Patients.cpp \
            pissSystemDataWare/SystemMetaData.cpp \
            pissSystemDataWare/Patient.cpp \
            pissImageProcessingMethods/igssMathLib/Derivation.cpp \
            pissImageProcessingMethods/igssMathLib/Convolution.cpp \
            pissImageProcessingMethods/igssSegmentationLib/VesselEnhancementFilter.cpp \
            pissImageProcessingMethods/igssSegmentationLib/Options.cpp \
            pissDiskImageReaderFactory/MRAFileReader.cpp \
            pissIHM/pissMainWindow/PatientsWidget.cpp \
            pissIHM/pissMainWindow/SurgerySystemWidget.cpp \
            pissIHM/pissMainWindow/ReplaysWidget.cpp \
            pissImageProcessingMethods/ImageProcessingFactory.cpp \
            pissImageProcessingMethods/ErrorMessage.cpp \
            pissIHM/pissMainWindow/AlgorithmTestPlatform.cpp \
            pissDiskImageReaderFactory/DicomCDRomReader.cpp \
            pissIHM/SurgeryPlanWindow/SurgeryPlanWindow.cpp \
            pissIHM/GuiComponentLib/CPushButton.cpp \
            pissIHM/GuiComponentLib/PlottingBoard.cpp \
            pissIHM/GuiComponentLib/ColorPoint.cpp \
            pissIHM/GuiComponentLib/HistogramPoint.cpp \
            pissIHM/GuiComponentLib/PlotPoint.cpp \
            pissIHM/GuiComponentLib/qcustomplot.cpp \
            pissIHM/GuiComponentLib/TransferPoint.cpp \
            pissIHM/SurgeryPlanWindow/PatientWidgetConfigurationBoard.cpp \
            pissIHM/GuiComponentLib/ColorChooseWindow.cpp \
            pissIHM/CurveReformationWindow/CurveReformationWindow.cpp \
            pissIHM/GuidewareTrackingWindow/GuidewareTrackingWindow.cpp \
            pissSystemDataWare/CTBidimensionnelFrame.cpp \
            pissIHM/pissMainWindow/PatientInformationWidget.cpp \
            pissIHM/pissMainWindow/PersonnelImageLabel.cpp \
            pissImageProcessingMethods/igssGeneralLib/GeneralInformationAnalyser.cpp \
            pissIHM/pissMainWindow/SurgeryLoadingWindow.cpp \
            pissDiskImageReaderFactory/ImageFileInterface.cpp \
            pissDiskImageReaderFactory/ImageFileInterface_Dicomdir.cpp \
            pissDiskImageReaderFactory/ImageFileInterface_RawMhd.cpp \
    pissConnectionFactory/IgssClient.cpp \
    pissConnectionFactory/IgssConnectionDoctor.cpp \
    pissConnectionFactory/IgssServeur.cpp \
    pissConnectionFactory/TacheDuReception.cpp \
    pissConnectionFactory/TacheDuTransmission.cpp \
    pissConnectionFactory/HandShakeTask.cpp \
    pissIHM/pissMainWindow/PatientItem.cpp

HEADERS  += \
            pissDispatcher/SystemDispatcher.h \
            pissSystemDataWare/SystemDataBase.h \
            pissSystemDataWare/igssImage.h \
            pissImageProcessingMethods/igssGeneralLib/igssVtkImageConverter.h \
            pissSystemDataWare/CenterLinePoint.h \
            pissIHM/pissMainWindow/igssMainWindow.h \
            pissSystemDataWare/Patients.h \
            pissSystemDataWare/SystemMetaData.h \
            pissSystemDataWare/Patient.h \
            pissImageProcessingMethods/igssMathLib/Derivation.h \
            pissImageProcessingMethods/igssMathLib/Convolution.h \
            pissImageProcessingMethods/igssSegmentationLib/VesselEnhancementFilter.h \
            pissImageProcessingMethods/igssSegmentationLib/Options.h \
            pissDiskImageReaderFactory/MRAFileReader.h \
            pissIHM/pissMainWindow/PatientsWidget.h \
            pissIHM/pissMainWindow/SurgerySystemWidget.h \
            pissIHM/pissMainWindow/ReplaysWidget.h \
            pissImageProcessingMethods/ImageProcessingFactory.h \
            pissImageProcessingMethods/ErrorMessage.h \
            pissIHM/pissMainWindow/AlgorithmTestPlatform.h \
            pissDiskImageReaderFactory/DicomCDRomReader.h \
            pissIHM/SurgeryPlanWindow/SurgeryPlanWindow.h \
            pissIHM/GuiComponentLib/CPushButton.h \
            pissIHM/GuiComponentLib/PlottingBoard.h \
            pissIHM/GuiComponentLib/ColorPoint.h \
            pissIHM/GuiComponentLib/HistogramPoint.h \
            pissIHM/GuiComponentLib/PlotPoint.h \
            pissIHM/GuiComponentLib/qcustomplot.h \
            pissIHM/GuiComponentLib/TransferPoint.h \
            pissIHM/SurgeryPlanWindow/PatientWidgetConfigurationBoard.h \
            pissIHM/GuiComponentLib/ColorChooseWindow.h \
            pissIHM/CurveReformationWindow/CurveReformationWindow.h \
            pissIHM/GuidewareTrackingWindow/GuidewareTrackingWindow.h \
            pissIHM/pissMainWindow/PatientInformationWidget.h\
            pissSystemDataWare/CTBidimensionnelFrame.h \
            pissIHM/pissMainWindow/PersonnelImageLabel.h \
            pissImageProcessingMethods/igssGeneralLib/GeneralInformationAnalyser.h \
            pissIHM/pissMainWindow/SurgeryLoadingWindow.h \
            pissDiskImageReaderFactory/ImageFileInterface.h \
            pissDiskImageReaderFactory/ImageFileInterface_Dicomdir.h \
            pissDiskImageReaderFactory/ImageFileInterface_RawMhd.h \
    pissConnectionFactory/IgssClient.h \
    pissConnectionFactory/IgssConnectionDoctor.h \
    pissIHM/SurgeryPlanWindow/digitalSurgeryTime.h \
    pissConnectionFactory/IgssServeur.h \
    pissConnectionFactory/TacheDuReception.h \
    pissConnectionFactory/TacheDuTransmission.h \
    pissConnectionFactory/HandShakeTask.h \
    pissIHM/pissMainWindow/PatientItem.h


win32:INCLUDEPATH += "C:\Program Files\VTK\include\vtk-6.2"
unix:INCLUDEPATH += $$PWD/../../../../../usr/local/include/vtk-6.2
unix:DEPENDPATH += $$PWD/../../../../../usr/local/include/vtk-6.2

unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkalglib-6.2 -lvtkChartsCore-6.2 -lvtkCommonColor-6.2 -lvtkCommonComputationalGeometry-6.2 -lvtkCommonCore-6.2 -lvtkCommonDataModel-6.2 -lvtkCommonExecutionModel-6.2 -lvtkCommonMath-6.2 -lvtkCommonMisc-6.2  -lvtkCommonSystem-6.2  -lvtkCommonTransforms-6.2  -lvtkDICOMParser-6.2  -lvtkDomainsChemistry-6.2  -lvtkexoIIc-6.2  -lvtkexpat-6.2  -lvtkFiltersAMR-6.2  -lvtkFiltersCore-6.2  -lvtkFiltersExtraction-6.2  -lvtkFiltersFlowPaths-6.2  -lvtkFiltersGeneral-6.2  -lvtkFiltersGeneric-6.2  -lvtkFiltersGeometry-6.2  -lvtkFiltersHybrid-6.2  -lvtkFiltersHyperTree-6.2  -lvtkFiltersImaging-6.2  -lvtkFiltersModeling-6.2  -lvtkFiltersParallel-6.2  -lvtkFiltersParallelImaging-6.2  -lvtkFiltersProgrammable-6.2  -lvtkFiltersSelection-6.2  -lvtkFiltersSMP-6.2  -lvtkFiltersSources-6.2  -lvtkFiltersStatistics-6.2  -lvtkFiltersTexture-6.2  -lvtkFiltersVerdict-6.2  -lvtkfreetype-6.2  -lvtkftgl-6.2  -lvtkGeovisCore-6.2  -lvtkgl2ps-6.2  -lvtkGUIsupportQt-6.2  -lvtkGUIsupportQtOpenGL-6.2  -lvtkGUIsupportQtSQL-6.2  -lvtkGUIsupportQtWebkit-6.2  -lvtkhdf5-6.2  -lvtkhdf5_hl-6.2  -lvtkImagingColor-6.2  -lvtkImagingCore-6.2  -lvtkImagingFourier-6.2  -lvtkImagingGeneral-6.2  -lvtkImagingHybrid-6.2  -lvtkImagingMath-6.2  -lvtkImagingMorphological-6.2  -lvtkImagingSources-6.2  -lvtkImagingStatistics-6.2  -lvtkImagingStencil-6.2  -lvtkInfovisCore-6.2  -lvtkInfovisLayout-6.2  -lvtkInteractionImage-6.2  -lvtkInteractionStyle-6.2  -lvtkInteractionWidgets-6.2  -lvtkIOAMR-6.2  -lvtkIOCore-6.2  -lvtkIOEnSight-6.2  -lvtkIOExodus-6.2  -lvtkIOExport-6.2  -lvtkIOGeometry-6.2  -lvtkIOImage-6.2 -lvtkIOImport-6.2  -lvtkIOInfovis-6.2  -lvtkIOLegacy-6.2  -lvtkIOLSDyna-6.2  -lvtkIOMINC-6.2  -lvtkIOMovie-6.2  -lvtkIONetCDF-6.2  -lvtkIOParallel-6.2  -lvtkIOParallelXML-6.2  -lvtkIOPLY-6.2  -lvtkIOSQL-6.2  -lvtkIOVideo-6.2  -lvtkIOXML-6.2  -lvtkIOXMLParser-6.2  -lvtkjpeg-6.2  -lvtkjsoncpp-6.2  -lvtklibxml2-6.2  -lvtkmetaio-6.2  -lvtkNetCDF-6.2  -lvtkNetCDF_cxx-6.2  -lvtkoggtheora-6.2  -lvtkParallelCore-6.2  -lvtkpng-6.2  -lvtkproj4-6.2  -lvtkRenderingAnnotation-6.2  -lvtkRenderingContext2D-6.2  -lvtkRenderingContextOpenGL-6.2  -lvtkRenderingCore-6.2  -lvtkRenderingFreeType-6.2  -lvtkRenderingFreeTypeOpenGL-6.2  -lvtkRenderingGL2PS-6.2  -lvtkRenderingImage-6.2  -lvtkRenderingLabel-6.2 -lvtkRenderingLIC-6.2 -lvtkRenderingLOD-6.2 -lvtkRenderingOpenGL-6.2 -lvtkRenderingQt-6.2 -lvtkRenderingVolume-6.2 -lvtkRenderingVolumeOpenGL-6.2 -lvtksqlite-6.2 -lvtksys-6.2 -lvtktiff-6.2 -lvtkverdict-6.2 -lvtkViewsContext2D-6.2 -lvtkViewsCore-6.2 -lvtkViewsInfovis-6.2 -lvtkViewsQt-6.2 -lvtkzlib-6.2

# importer des librairies de vtk...
win32:LIBS += $$quote(C:\Program Files\VTK\lib\QVTKWidgetPlugin.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkalglib-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkChartsCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonColor-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonComputationalGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonDataModel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonExecutionModel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonMath-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonMisc-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonSystem-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonTransforms-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkDICOMParser-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkDomainsChemistry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkexoIIc-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkexpat-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersAMR-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersExtraction-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersFlowPaths-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeneral-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeneric-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersHybrid-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersHyperTree-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersImaging-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersModeling-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersParallel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersParallelImaging-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersProgrammable-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSelection-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSMP-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSources-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersStatistics-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersTexture-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersVerdict-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkfreetype-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkftgl-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGeovisCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkgl2ps-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUIsupportQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUIsupportQtOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUIsupportQtSQL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUIsupportQtWebkit-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkhdf5-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkhdf5_hl-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingColor-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingFourier-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingGeneral-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingHybrid-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingMath-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingMorphological-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingSources-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingStatistics-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingStencil-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInfovisCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInfovisLayout-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionStyle-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionWidgets-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOAMR-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOEnSight-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOExodus-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOExport-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOImport-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOInfovis-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOLegacy-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOLSDyna-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOMINC-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOMovie-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIONetCDF-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOParallel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOParallelXML-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOPLY-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOSQL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOVideo-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOXML-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOXMLParser-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkjpeg-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkjsoncpp-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtklibxml2-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkmetaio-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkNetCDF-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkNetCDF_cxx-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkoggtheora-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkParallelCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkpng-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkproj4-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingAnnotation-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingContext2D-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingContextOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingFreeType-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingFreeTypeOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingGL2PS-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLabel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLIC-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLOD-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingVolume-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingVolumeOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtksqlite-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtksys-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtktiff-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkverdict-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsContext2D-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsInfovis-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkzlib-6.2.lib)


#win32:INCLUDEPATH += "C:\Program Files\ITK\include\ITK-4.7"
#unix:INCLUDEPATH += "/usr/local/include/ITK-4.7"
#macx: INCLUDEPATH += $$PWD/../../../../../usr/local/include/ITK-4.7
#macx: DEPENDPATH += $$PWD/../../../../../usr/local/include/ITK-4.7

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Program Files/ITK/lib/ -lITKBiasCorrection-4.7 -lITKBioCell-4.7 -lITKCommon -lITKDICOMParser-4.7 -litkdouble-conversion-4.7 -lITKEXPAT-4.7 -lITKFEM-4.7 -litkgdcmCommon-4.7 -litkgdcmDICT-4.7 -litkgdcmDSED-4.7 -litkgdcmIOD-4.7 -litkgdcmjpeg8-4.7 -litkgdcmjpeg12-4.7 -litkgdcmjpeg16-4.7 -litkgdcmMSFF-4.7 -lITKgiftiio-4.7 -litkhdf5_cpp-4.7 -litkhdf5-4.7 -lITKIOBioRad-4.7 -lITKIOBMP-4.7 -lITKIOCSV-4.7 -lITKIOGDCM-4.7 -lITKIOGE-4.7 -lITKIOGIPL-4.7 -lITKIOHDF5-4.7 -lITKIOImageBase-4.7 -lITKIOIPL-4.7 -lITKIOJPEG-4.7 -lITKIOLSM-4.7 -lITKIOMesh-4.7 -lITKIOMeta-4.7 -lITKIOMRC-4.7 -lITKIONIFTI-4.7 -lITKIONRRD-4.7 -lITKIOPNG-4.7 -lITKIOSiemens-4.7 -lITKIOSpatialObjects-4.7 -lITKIOStimulate-4.7 -lITKIOTIFF-4.7 -lITKIOTransformBase-4.7 -lITKIOTransformHDF5-4.7 -lITKIOTransformInsightLegacy-4.7 -lITKIOTransformMatlab-4.7 -lITKIOVTK-4.7 -lITKIOXML-4.7 -litkjpeg-4.7 -lITKKLMRegionGrowing-4.7 -lITKLabelMap-4.7 -lITKMesh-4.7 -lITKMetaIO-4.7 -litkNetlibSlatec-4.7 -lITKniftiio-4.7 -lITKNrrdIO-4.7 -litkopenjpeg-4.7 -lITKOptimizers-4.7 -lITKOptimizersv4-4.7 -lITKPath-4.7 -litkpng-4.7 -lITKPolynomials-4.7 -lITKQuadEdgeMesh-4.7 -lITKSpatialObjects-4.7 -lITKStatistics-4.7 -litksys-4.7 -litktiff-4.7 -litkv3p_lsqr-4.7 -litkv3p_netlib-4.7 -litkvcl-4.7 -lITKVideoCore-4.7 -lITKVideoIO-4.7 -litkvnl_algo-4.7 -litkvnl-4.7 -lITKVNLInstantiation-4.7 -lITKVTK-4.7 -lITKWatersheds-4.7 -litkzlib-4.7 -lITKznz-4.7
#unix: LIBS += -L$$PWD/usr/local/lib/ -lITKBiasCorrection-4.7 -lITKBioCell-4.7 -lITKCommon-4.7 -lITKDICOMParser-4.7 -litkdouble-conversion-4.7 -lITKEXPAT-4.7 -lITKFEM-4.7 -litkgdcmCommon-4.7 -litkgdcmDICT-4.7 -litkgdcmDSED-4.7 -litkgdcmIOD-4.7 -litkgdcmjpeg8-4.7 -litkgdcmjpeg12-4.7 -litkgdcmjpeg16-4.7 -litkgdcmMSFF-4.7 -lITKgiftiio-4.7 -litkhdf5_cpp-4.7 -litkhdf5-4.7 -lITKIOBioRad-4.7 -lITKIOBMP-4.7 -lITKIOCSV-4.7 -lITKIOGDCM-4.7 -lITKIOGE-4.7 -lITKIOGIPL-4.7 -lITKIOHDF5-4.7 -lITKIOImageBase-4.7 -lITKIOIPL-4.7 -lITKIOJPEG-4.7 -lITKIOLSM-4.7 -lITKIOMesh-4.7 -lITKIOMeta-4.7 -lITKIOMRC-4.7 -lITKIONIFTI-4.7 -lITKIONRRD-4.7 -lITKIOPNG-4.7 -lITKIOSiemens-4.7 -lITKIOSpatialObjects-4.7 -lITKIOStimulate-4.7 -lITKIOTIFF-4.7 -lITKIOTransformBase-4.7 -lITKIOTransformHDF5-4.7 -lITKIOTransformInsightLegacy-4.7 -lITKIOTransformMatlab-4.7 -lITKIOVTK-4.7 -lITKIOXML-4.7 -litkjpeg-4.7 -lITKKLMRegionGrowing-4.7 -lITKLabelMap-4.7 -lITKMesh-4.7 -lITKMetaIO-4.7 -litkNetlibSlatec-4.7 -lITKniftiio-4.7 -lITKNrrdIO-4.7 -litkopenjpeg-4.7 -lITKOptimizers-4.7 -lITKOptimizersv4-4.7 -lITKPath-4.7 -litkpng-4.7 -lITKPolynomials-4.7 -lITKQuadEdgeMesh-4.7 -lITKSpatialObjects-4.7 -lITKStatistics-4.7 -litksys-4.7 -litktiff-4.7 -litkv3p_lsqr-4.7 -litkv3p_netlib-4.7 -litkvcl-4.7 -lITKVideoCore-4.7 -lITKVideoIO-4.7 -litkvnl_algo-4.7 -litkvnl-4.7 -lITKVNLInstantiation-4.7 -lITKVTK-4.7 -lITKWatersheds-4.7 -litkzlib-4.7 -lITKznz-4.7
#macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lITKBiasCorrection-4.7 -lITKBioCell-4.7 -lITKCommon-4.7 -lITKDICOMParser-4.7 -litkdouble-conversion-4.7 -lITKEXPAT-4.7 -lITKFEM-4.7 -litkgdcmCommon-4.7 -litkgdcmDICT-4.7 -litkgdcmDSED-4.7 -litkgdcmIOD-4.7 -litkgdcmjpeg8-4.7 -litkgdcmjpeg12-4.7 -litkgdcmjpeg16-4.7 -litkgdcmMSFF-4.7 -lITKgiftiio-4.7 -litkhdf5_cpp-4.7 -litkhdf5-4.7 -lITKIOBioRad-4.7 -lITKIOBMP-4.7 -lITKIOCSV-4.7 -lITKIOGDCM-4.7 -lITKIOGE-4.7 -lITKIOGIPL-4.7 -lITKIOHDF5-4.7 -lITKIOImageBase-4.7 -lITKIOIPL-4.7 -lITKIOJPEG-4.7 -lITKIOLSM-4.7 -lITKIOMesh-4.7 -lITKIOMeta-4.7 -lITKIOMRC-4.7 -lITKIONIFTI-4.7 -lITKIONRRD-4.7 -lITKIOPNG-4.7 -lITKIOSiemens-4.7 -lITKIOSpatialObjects-4.7 -lITKIOStimulate-4.7 -lITKIOTIFF-4.7 -lITKIOTransformBase-4.7 -lITKIOTransformHDF5-4.7 -lITKIOTransformInsightLegacy-4.7 -lITKIOTransformMatlab-4.7 -lITKIOVTK-4.7 -lITKIOXML-4.7 -litkjpeg-4.7 -lITKKLMRegionGrowing-4.7 -lITKLabelMap-4.7 -lITKMesh-4.7 -lITKMetaIO-4.7 -litkNetlibSlatec-4.7 -lITKniftiio-4.7 -lITKNrrdIO-4.7 -litkopenjpeg-4.7 -lITKOptimizers-4.7 -lITKOptimizersv4-4.7 -lITKPath-4.7 -litkpng-4.7 -lITKPolynomials-4.7 -lITKQuadEdgeMesh-4.7 -lITKSpatialObjects-4.7 -lITKStatistics-4.7 -litksys-4.7 -litktiff-4.7 -litkv3p_lsqr-4.7 -litkv3p_netlib-4.7 -litkvcl-4.7 -lITKVideoCore-4.7 -lITKVideoIO-4.7 -litkvnl_algo-4.7 -litkvnl-4.7 -lITKVNLInstantiation-4.7 -lITKVTK-4.7 -lITKWatersheds-4.7 -litkzlib-4.7 -lITKznz-4.7

#INCLUDEPATH += $$PWD/../../../../../usr/local/include/ITK-4.7
#DEPENDPATH += $$PWD/../../../../../usr/local/include/ITK-4.7


#-------------------------------------------------

## MSVCRT link option (static or dynamic, it must be the same with your Qt SDK link option)
#MSVCRT_LINK_FLAG_DEBUG   = "/MDd"
#MSVCRT_LINK_FLAG_RELEASE = "/MD"

## CUDA settings
#CUDA_DIR = "D:/CUDA"                # Path to cuda toolkit install
#SYSTEM_NAME = x64                 # Depending on your system either 'Win32', 'x64', or 'Win64'
#SYSTEM_TYPE = 64                    # '32' or '64', depending on your system
#CUDA_ARCH = sm_30                   # Type of CUDA architecture
#NVCC_OPTIONS = --use_fast_math

## include paths
#INCLUDEPATH += $$CUDA_DIR/include \

## library directories
#QMAKE_LIBDIR += $$CUDA_DIR/lib/$$SYSTEM_NAME \

## The following makes sure all path names (which often include spaces) are put between quotation marks
#CUDA_INC = $$join($$CUDA_DIR/include,'" -I"','-I"','"')

## Add the necessary libraries
#CUDA_LIB_NAMES = cudart_static kernel32 user32 gdi32 winspool comdlg32 \
#                 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32 \
#                 #freeglut glew32

#for(lib, CUDA_LIB_NAMES) {
#    CUDA_LIBS += -l$$lib
#}
#LIBS += $$CUDA_LIBS

## Configuration of the Cuda compiler
#CONFIG(debug, debug|release) {
#    # Debug mode
#    cuda_d.input = CUDA_SOURCES
#    cuda_d.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.obj
#    cuda_d.commands = $$CUDA_DIR/bin/nvcc.exe -D_DEBUG $$NVCC_OPTIONS $$CUDA_INC $$CUDA_LIBS \
#                      --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
#                      --compile -cudart static -g -DWIN32 -D_MBCS \
#                      -Xcompiler "/wd4819,/EHsc,/W3,/nologo,/Od,/Zi,/RTC1" \
#                      -Xcompiler $$MSVCRT_LINK_FLAG_DEBUG \
#                      -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda_d.dependency_type = TYPE_C
#    QMAKE_EXTRA_COMPILERS += cuda_d
#}
#else {
#    # Release mode
#    cuda.input = CUDA_SOURCES
#    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.obj
#    cuda.commands = $$CUDA_DIR/bin/nvcc.exe $$NVCC_OPTIONS $$CUDA_INC $$CUDA_LIBS \
#                    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
#                    --compile -cudart static -DWIN32 -D_MBCS \
#                    -Xcompiler "/wd4819,/EHsc,/W3,/nologo,/O2,/Zi" \
#                    -Xcompiler $$MSVCRT_LINK_FLAG_RELEASE \
#                    -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda.dependency_type = TYPE_C
#    QMAKE_EXTRA_COMPILERS += cuda

#}
