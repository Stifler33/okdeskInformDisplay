#include "informdisplay.h"
#include "./ui_informdisplay.h"

InformDisplay::InformDisplay() : ui(new Ui::InformDisplay)
{
    ui->setupUi(this);
    timer = new(QTimer);
    timer->setInterval(1000);
}

InformDisplay::~InformDisplay()
{
    delete ui;
}

void InformDisplay::setApi(OkdeskApi *_api)
{
    okdeskApi = _api;
    ui->labelNameAccount->setText(okdeskApi->getNameAccount());
    timer->start();
    connect(timer, &QTimer::timeout, [this](){
       ui->labelTime->setText(QTime::currentTime().toString());
    });
}

