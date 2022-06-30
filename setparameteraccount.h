#ifndef SETPARAMETERACCOUNT_H
#define SETPARAMETERACCOUNT_H

#include <QWidget>

namespace Ui {
class setParameterAccount;
}

class setParameterAccount : public QWidget
{
    Q_OBJECT

public:
    explicit setParameterAccount(QWidget *parent = nullptr);
    ~setParameterAccount();

private:
    Ui::setParameterAccount *ui;
};

#endif // SETPARAMETERACCOUNT_H
