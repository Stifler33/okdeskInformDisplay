#include "informdisplay.h"
#include "setparameteraccount.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    setParameterAccount setWindow;
    setWindow.show();
    QTimer::singleShot(2000, &setWindow, SLOT(close()));
    InformDisplay w;
    w.show();
    return a.exec();
}
