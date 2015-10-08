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

// Aqcuire the path of the databse on execution of the login dialog.
// Linux and Windows have different conventions for their filesystem
// hierarchy and structure.
#ifdef Q_OS_LINUX
    bool is_linux = true;
    bool is_windows = false;
#elif Q_OS_WIN
    bool is_linux = false;
    bool is_windows = true;
#endif

// Construct the login dialog using a QWidget and QDialog. On executiong of
// the login dialog, a connection to the database must be first established.
// The login credentials will be checked by the database to determine if the
// user is a valid user in the database of the inventory management system.
//
// args:
//    *parent (QWidget): The widget that is used for drawing the child widget.
LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::LoginDialog)
{
    if (is_linux)
        pathDatabase = qApp->applicationDirPath() + "/sql/db.sqlite3";

    else if (is_windows)
        pathDatabase = qApp->applicationDirPath() + "/sql/db.sqlite3";

    ui->setupUi(this);

    posDatabase = QSqlDatabase::addDatabase("QSQLITE");
    posDatabase.setDatabaseName(pathDatabase);

    QFileInfo sqlFile(pathDatabase);

    if(sqlFile.isFile() && posDatabase.open())
        ui->loginResult->setText("[+]Database connection established");

    else
        ui->loginResult->setText("[!]Invalid database");
}

// TO DO: Needs to be handled by other class, the login dialog is a seperate
//        entity from the actual inventory management system. The login dialog
//        will exit and execute the inventory management system. The database must
//        remain open.
LoginDialog::~LoginDialog()
{
    delete ui;
    posDatabase.close(); // Remove this later.
}

// Slot for the login button clicked signal. The button will attempt to login
// the user by checking the users table of the database to see if the user has
// valid credentials or if the user is a valid user in the system.
void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    if(!posDatabase.isOpen())
    {
        ui->loginResult->setText("[!]Database connection lost");
        return;
    }

    QString query = "SELECT User_ID, Password FROM Users WHERE User_ID=\'" +
                    username + "\' AND Password=\'" + password + "\'";

    QSqlQuery sqlQuery;

    if(sqlQuery.exec(query) && sqlQuery.next())
    {
        ui->loginResult->setText("[+]Login successful");
        homePage.show();
        homePage.setDatabase(posDatabase);

        this->close();
    }

    else
        ui->loginResult->setText("[-]Invalid Username or Password");
}

// Slot for the cancel button clicked signal. The button will erase the
// contents of the username and password textbox.
void LoginDialog::on_cancelButton_clicked()
{
    ui->usernameInput->setText("");
    ui->passwordInput->setText("");
}
