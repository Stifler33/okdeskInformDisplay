#include "informdisplay.h"
#include "setparameteraccount.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    OkdeskApi okdeskApi;
    setParameterAccount setWindow(&okdeskApi);
    setWindow.show();
    InformDisplay w;
    QObject::connect(&setWindow, &setParameterAccount::quit, [&w](OkdeskApi *_api){
        w.setApi(_api);
        w.show();
    });
    return a.exec();
}
