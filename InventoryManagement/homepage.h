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
#include <QSqlDatabase>
#include <QCompleter>
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
    ~HomePage() { delete uiHomePage; database.close(); }

    // Allow the homepage to have access to the database.
    //
    // Args:
    //    posDatabase (QSqlDatabase): The database used by the application.
    void setDatabase(QSqlDatabase posDatabase) { database = posDatabase; }

private:
    Ui::HomePage* uiHomePage;
    QSqlDatabase database;
    Inventory inventory;
};

#endif
