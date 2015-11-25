#ifndef IGSSCONNECTIONDOCTOR_H
#define IGSSCONNECTIONDOCTOR_H

#include <QThread>

class IgssConnectionDoctor
{
public:
    IgssConnectionDoctor();
    ~IgssConnectionDoctor();

private:
    class ThreadConnectionDiagnosis : public QThread{
        public:
            void run();
            IgssConnectionDoctor *igssClient;
    };
};

#endif // IGSSCONNECTIONDOCTOR_H
