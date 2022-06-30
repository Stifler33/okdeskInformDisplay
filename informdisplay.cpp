#include "informdisplay.h"
#include "./ui_informdisplay.h"

InformDisplay::InformDisplay(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InformDisplay)
{
    ui->setupUi(this);
}

InformDisplay::~InformDisplay()
{
    delete ui;
}

