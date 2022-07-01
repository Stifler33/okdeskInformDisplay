#ifndef GENERAL_H
#define GENERAL_H
#include <QObject>
#include <QThread>
#include "setparameteraccount.h"
#include "okdeskapi.h"
class General : public QObject
{
    Q_OBJECT
    setParameterAccount *setWindow;
    OkdeskApi *okdeskApi;
    QThread thOkdeskApi;
public:
    General();
};

#endif // GENERAL_H
