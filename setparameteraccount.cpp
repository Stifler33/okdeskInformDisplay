#include "setparameteraccount.h"
#include "ui_setparameteraccount.h"

setParameterAccount::setParameterAccount(OkdeskApi *_okdeskApi) : okdeskApi(_okdeskApi),
    ui(new Ui::setParameterAccount)
{
    ui->setupUi(this);   
    connect(ui->buttonConnect, &QPushButton::clicked, this, &setParameterAccount::getParameters);
    connect(this, &setParameterAccount::callConnect, okdeskApi, &OkdeskApi::setAccountSettings);
    connect(okdeskApi, &OkdeskApi::sendResultConnect, this, &setParameterAccount::showResultConnect);
}

setParameterAccount::~setParameterAccount()
{
    delete ui;
}

void setParameterAccount::getParameters()
{
    emit callConnect("itconsalt", "55fbb943003c66a30caaabd803da63408afd531d");
}

void setParameterAccount::showResultConnect(QString result)
{
    ui->resultConnect->setText(result);
    if (result == "connect completed")
    {
        setParameterAccount::close();
        emit quit(okdeskApi);
    }
}
