#include "setparameteraccount.h"
#include "ui_setparameteraccount.h"

setParameterAccount::setParameterAccount(QWidget *parent) :
    QWidget(parent),
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
    emit callConnect(ui->name->toPlainText(), ui->api->toPlainText());
}

void setParameterAccount::showResultConnect(QString &result)
{
    ui->resultConnect->setText(result);
}
