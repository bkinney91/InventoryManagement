// homepage.h
//
// Author:      Bryce Kinney & Massimo Cannavo
//
// Description: The header definition for the homepage of the inventory
//              management system. The homepage is the navigation for the
//              application. It allows the user to perform specified operations
//              such as administration tasks and updating the inventory.

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "sqlDAL.h"
#include "inventory.h"

namespace Ui
{
    class HomePage;
}

// The homepage consists of a QMainWindow that creates the interface for the
// gui window. The QMainWindow class renders the gui of the home page window on
// the screen.
class HomePage : public QMainWindow
{
    Q_OBJECT

public:

    // Construct the homepage window.
    //
    // args:
    //    parent (QWidget*): The widget that is used for drawing the child widget.
    explicit HomePage(QWidget* parent = 0);

    // Destruct the homepage window.
    ~HomePage();

private:
    Ui::HomePage* uiHomePage;
    sqlDAL* sqlDB;
};

#endif
