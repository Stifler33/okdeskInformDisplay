#include <QApplication>
#include "general.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    General general;
    return a.exec();
}
