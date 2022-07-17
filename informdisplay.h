#ifndef INFORMDISPLAY_H
#define INFORMDISPLAY_H

#include <QMainWindow>
#include <okdeskapi.h>
#include <QTimer>
#include <QTime>
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
public slots:
    void getTasks(QJsonDocument *jDoc);
private:
    QJsonArray tasks;
    QTimer *timer;
    OkdeskApi *okdeskApi;
    Ui::InformDisplay *ui;
signals:
    void queryTask();
};
#endif // INFORMDISPLAY_H
