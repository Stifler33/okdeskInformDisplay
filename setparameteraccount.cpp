#include "setparameteraccount.h"
#include "ui_setparameteraccount.h"

setParameterAccount::setParameterAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setParameterAccount)
{
    ui->setupUi(this);
}

setParameterAccount::~setParameterAccount()
{
    delete ui;
}
