#ifndef LOGINWINDOWDIALOG_H
#define LOGINWINDOWDIALOG_H

#include <QWidget>

namespace Ui {
    class LoginWindowDialog;
}

class LoginWindowDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindowDialog(QWidget *parent = 0);
    ~LoginWindowDialog();

private:
    Ui::LoginWindowDialog *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // LOGINWINDOWDIALOG_H
