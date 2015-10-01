#include "loginDialog.h"
#include "ui_dialog.h"

// TO DO: Massimo Cannavo - Need to add comments when I have time.
//                        - Change path relative to Windows, Linux, and maybe also OSX users.
//                        - Remove redundant debug statements and message box.

#ifdef Q_OS_LINUX
#define pathDatabase "/home/massimo/pos/sql/accounts.sqlite" // Need to change this (fix path relative to Linux user)
#elif Q_WS_WIN
#define pathDatabase "C:" // Need to change this (relative to Windows user)
#endif

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    posDatabase = QSqlDatabase::addDatabase("QSQLITE");
    posDatabase.setDatabaseName(pathDatabase);

    QFileInfo sqlFile(pathDatabase);

    if(sqlFile.isFile() && posDatabase.open())
    {
        ui->loginResult->setText("[+]Database connection established");
    }

    else
    {
        ui->loginResult->setText("[!]Invalid database");
    }
}

LoginDialog::~LoginDialog()
{
    delete ui;

    qDebug() << "Terminating the connection"; // Debug statements should be removed later.

    posDatabase.close();
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
