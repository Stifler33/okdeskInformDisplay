#include "informdisplay.h"
#include "setparameteraccount.h"
#include <QThread>
#include <QApplication>
#include <QTimer>
#include "ui_setparameteraccount.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    QThread threadOkdeskApi;
    Ui::setParameterAccount *uiSetParameter = new Ui::setParameterAccount;
    OkdeskApi *okdeskApi = new OkdeskApi;
    okdeskApi->moveToThread(&threadOkdeskApi);
    setParameterAccount setWindow;
    OkdeskApi::connect(uiSetParameter->buttonConnect, &QPushButton::clicked, setWindow, &setParameterAccount::getParameters);
    setWindow.show();

    //InformDisplay w;
    //w.show();
    return a.exec();
}
