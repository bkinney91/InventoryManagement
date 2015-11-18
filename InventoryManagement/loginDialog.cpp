// loginDialog.cpp
//
// Author:      Massimo Cannavo
//
// Description: The implementation of the login dialog. The user will be
//              prompted with a dialog to login into the inventory management
//              system. On success login, the graphical user interface (gui)
//              of the inventory management system will be executed.

#include "loginDialog.h"
#include "ui_loginDialog.h"

// Construct the login dialog using a QWidget and QDialog. On executiong of
// the login dialog, a connection to the database must be first established.
// The login credentials will be checked by the database to determine if the
// user is a valid user in the database of the inventory management system.
//
// args:
//    parent (QWidget*): The widget that is used for drawing the child widget.
LoginDialog::LoginDialog(QWidget* parent) : QDialog(parent),
    uiLogin(new Ui::LoginDialog)
{
    uiLogin->setupUi(this);

    QString sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";

    QFileInfo sqlFile(sqlPath);
    sqlDAL* sqlDB = sqlDAL::getInstance(sqlPath);

    if(sqlDB->connect() && sqlFile.isFile())
        uiLogin->loginResult->setText("[+]Database connection established");

    else
        uiLogin->loginResult->setText("[!]Invalid database");
}

// Slot for the login button clicked signal. The button will attempt to login
// the user by checking the users table of the database to see if the user has
// valid credentials or if the user is a valid user in the system.
void LoginDialog::on_loginButton_clicked()
{
    QString username = uiLogin->usernameInput->text();
    QString password = uiLogin->passwordInput->text();

    if(!sqlDB->isOpen())
    {
        uiLogin->loginResult->setText("[!]Database connection lost");
        return;
    }

    QString sqlQuery = "SELECT User_ID, Password FROM Users WHERE User_ID=\'" +
                        username + "\' AND Password=\'" + password + "\'";

    if(sqlDB->query(sqlQuery) && sqlDB->result())
    {
        uiLogin->loginResult->setText("[+]Login successful");
        homePage.show();
        this->close();
    }

    else
        uiLogin->loginResult->setText("[-]Invalid Username or Password");
}

// Slot for the cancel button clicked signal. The button will erase the
// contents of the username and password textbox.
void LoginDialog::on_cancelButton_clicked()
{
    uiLogin->usernameInput->setText("");
    uiLogin->passwordInput->setText("");
}

// Destruct the login dialog.
LoginDialog::~LoginDialog()
{
    delete uiLogin;
}
