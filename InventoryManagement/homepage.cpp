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
#include "reports.h"
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

//Calls dashboard constructor and sets all data members to relevant UI items
//Written by Bryce Kinney
void HomePage::displayDashboard()
{
    Dashboard* dashboard = Dashboard::getDashboardInstance();
    uiHomePage->OrderDisplay->setText(dashboard->mtdOrdersCost);
    uiHomePage->SalesDisplay->setText(dashboard->mtdOrdersCost);
    uiHomePage->OverheadCostDisplay->setText(dashboard->overheadCost);
    uiHomePage->OverheadValueDisplay->setText(dashboard->overheadValue);
    uiHomePage->OverheadNetDisplay->setText(dashboard->overheadNet);
    uiHomePage->outOfStockItems->setModel(dashboard->outOfStockTable);
    uiHomePage->outOfStockItems->resizeRowsToContents();
    uiHomePage->outOfStockItems->resizeColumnsToContents();

}

//
void HomePage::displayInventory(QSqlQueryModel* inventoryTable)
{
    uiHomePage->inventoryTable->setModel(inventoryTable);
    uiHomePage->inventoryTable->resizeRowsToContents();
    uiHomePage->inventoryTable->resizeColumnsToContents();
}


// Destruct the homepage window.
HomePage::~HomePage()
{
    delete uiHomePage;
    sqlDB->disconnect();
}

void HomePage::on_addRecord_clicked()
{

}

void HomePage::on_removeRecord_clicked()
{

}

void HomePage::on_ReportsDropDown_currentIndexChanged(const QString &arg1)
{
    QString report =  uiHomePage->ReportsDropDown->currentText();
    Reports reportObj;
    QSqlQueryModel* reportTable = reportObj.queryReports(report);
    uiHomePage->reportTable->setModel(reportTable);
    uiHomePage->reportTable->resizeRowsToContents();
    uiHomePage->reportTable->resizeColumnsToContents();


}
