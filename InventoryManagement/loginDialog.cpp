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

void LoginDialog::on_cancelButton_clicked()
{
    ui->usernameInput->setText("");
    ui->passwordInput->setText("");
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    if(!posDatabase.isOpen())
    {
        qDebug() << "No connection to database";
        return;
    }

    QString query = "SELECT Username, Password, Role FROM Users WHERE Username=\'" +
                    username + "\' AND Password=\'" + password + "\'";

    QSqlQuery sqlQuery;

    if(sqlQuery.exec(query) && sqlQuery.next())
    {
        ui->loginResult->setText("[+]Attempting to login");

        QString message = "Username: " + sqlQuery.value(0).toString() + "\n" +
                          "Password: " + sqlQuery.value(1).toString() + "\n" +
                          "Role: " + sqlQuery.value(2).toString();

        QMessageBox::warning(this, "Login established", message); // Fix this later.
    }

    else
    {
        ui->loginResult->setText("[-]Invalid Username or Password");
    }
}
