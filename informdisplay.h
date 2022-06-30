#ifndef INFORMDISPLAY_H
#define INFORMDISPLAY_H

#include <QMainWindow>
#include <okdeskapi.h>
QT_BEGIN_NAMESPACE
namespace Ui { class InformDisplay; }

QT_END_NAMESPACE


class InformDisplay : public QMainWindow
{
    Q_OBJECT

public:
    InformDisplay(QWidget *parent = nullptr);
    ~InformDisplay();

private:
    Ui::InformDisplay *ui;
};
#endif // INFORMDISPLAY_H
