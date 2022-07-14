#include "informdisplay.h"
#include "setparameteraccount.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    OkdeskApi okdeskApi;
    setParameterAccount setWindow(&okdeskApi);
    setWindow.show();

    //InformDisplay w;
    //w.show();
    return a.exec();
}
