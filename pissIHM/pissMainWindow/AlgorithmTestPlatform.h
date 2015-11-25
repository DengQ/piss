#ifndef ALGORITHMTESTPLATFORM_H
#define ALGORITHMTESTPLATFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QFont>
#include <QProgressBar>
#include <SystemDispatcher.h>
//#include <Windows.h>
#include <iostream>

class AlgorithmTestPlatform : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmTestPlatform(SystemDispatcher* dispatcher, int appWidth, int appHeight);

    void setSystemStatus(QString status);
    void getPatientsStatus();
    void initVariable();
    void constructIHM();
    void setConnections();

private:
    //SYSTEM_INFO
    QHBoxLayout* platformLayout;
    QVBoxLayout* terminalWindowLayout;
    QGridLayout* systemUsageStatusLayout;

    QTextEdit* systemStatus;
    QLineEdit* systemCommand;
    SystemDispatcher* dispatcher;

    QFont* caracterStyle;

    QLabel* systemUsageStatusWidget;
    QWidget* terminalWindow;

    QLabel* cpuLabel;
    QLabel* ramLabel;
    QLabel* diskLable;
    QLabel* netLable;

    QProgressBar* cpuProgressBar;
    QProgressBar* ramProgressBar;
    QProgressBar* diskProgressBar;
    QProgressBar* netProgressBar;

    QString labelStyleSheet;
    QString progressBarStyleSheet;

    int appWidth;
    int appHeight;

signals:
private slots:
    void doParseCommand();
};

#endif // ALGORITHMTESTPLATFORM_H
