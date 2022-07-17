#ifndef INFORMDISPLAY_H
#define INFORMDISPLAY_H

#include <QMainWindow>
#include <okdeskapi.h>
#include <QTimer>
#include <QTime>
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui { class InformDisplay; }

QT_END_NAMESPACE

class InformDisplay : public QMainWindow
{
    Q_OBJECT

public:
    InformDisplay();
    ~InformDisplay();
    void setApi(OkdeskApi *_api);
private:
    QTimer *timer;
    OkdeskApi *okdeskApi;
    Ui::InformDisplay *ui;
};
#endif // INFORMDISPLAY_H
