// homepage.h
//
// Author:      Bryce Kinney & Massimo Cannavo
//
// Description: The implementation for the homepage of the inventory
//              management system. The homepage is the navigation for the
//              application. It allows the user to perform specified operations
//              such as administration tasks and updating the inventory.

#include "homepage.h"
#include "ui_homepage.h"

// Construct the homepage window using a QWidget and QWindow. The login dialog
// will terminate and instantiate the homepage window, if the user's credentials
// were validated.
//
// args:
//    parent (QWidget*): The widget that is used for drawing the child widget.
HomePage::HomePage(QWidget* parent) : QMainWindow(parent),
    uiHomePage(new Ui::HomePage)
{
    uiHomePage->setupUi(this);

    QString sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";
    sqlDB = sqlDAL::getInstance(sqlPath);
}

// Destruct the homepage window.
HomePage::~HomePage()
{
    delete uiHomePage;
    sqlDB->disconnect();
}
