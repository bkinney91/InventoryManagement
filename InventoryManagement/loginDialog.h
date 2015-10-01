#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

// TO DO: Massimo Cannavo - Need to add comments when I have time.
//                        - Change path relative to Windows, Linux, and maybe also OSX users.
//                        - Remove redundant debug statements and message box.

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_loginButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::LoginDialog *ui;

    QSqlDatabase posDatabase;
    QString pathDatabase;
};

#endif // DIALOG_H
