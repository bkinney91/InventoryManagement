// loginDialog.h
//
// Author:      Massimo Cannavo
//
// Description: The header definition for the login dialog. The user will be
//              prompted with a dialog to login into the inventory management
//              system. On success login, the graphical user interface (gui)
//              of the inventory management system will be executed.

#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include <QFileInfo>
#include "sqlDAL.h"
#include "homepage.h"

namespace Ui
{
    class LoginDialog;
}

// The login dialog consists of a QDialog that creates the interface for the
// gui dialog. The QDialog class renders the gui of the dialog on the screen.
// The login dialog will interface with the Data Access Layer (DAL) to initiate
// a connection to the SQL database and query for the user's login.
class LoginDialog : public QDialog
{
    Q_OBJECT

public:

    // Construct the login dialog.
    //
    // args:
    //    parent (QWidget*): The widget that is used for drawing the child widget.
    explicit LoginDialog(QWidget* parent = 0);
    QString sqlPath;
    // Destruct the login dialog.
    ~LoginDialog();

private slots:
    void on_loginButton_clicked();  // Slot for the login button clicked signal.
    void on_cancelButton_clicked(); // Slot for the cancel button clicked signal.

private:
    Ui::LoginDialog* uiLogin;
    HomePage homePage;
    sqlDAL* sqlDB;
};

#endif
