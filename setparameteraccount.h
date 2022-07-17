#ifndef SETPARAMETERACCOUNT_H
#define SETPARAMETERACCOUNT_H

#include <QWidget>
#include "okdeskapi.h"
namespace Ui {
class setParameterAccount;
}

class setParameterAccount : public QWidget
{
    Q_OBJECT

public:
    setParameterAccount(OkdeskApi *_okdeskApi);
    ~setParameterAccount();
public slots:
    void getParameters();
    void showResultConnect(QString result);
signals:
    void callConnect(QString name, QString api);
    void quit(OkdeskApi *_api);
private:
    Ui::setParameterAccount *ui;
    OkdeskApi *okdeskApi;
};

#endif // SETPARAMETERACCOUNT_H
