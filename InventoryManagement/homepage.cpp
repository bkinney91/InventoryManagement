// homepage.h
//
// Author:      Bryce Kinney & Massimo Cannavo
//
// Description: The implementation for the homepage of the inventory
//              management system. The homepage is the navigation for the
//              application. It allows the user to perform specified operations
//              such as administration tasks and updating the inventory.
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "homepage.h"
#include "ui_homepage.h"
#include "reports.h"
#include "administration.h"
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
    QString partNum = uiHomePage->add_partNum->text();
        QString qty = uiHomePage->add_qty->text();
        QString partName = uiHomePage->add_partName->text();

        QString sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";

        if(!sqlDB->isOpen())
        {
            uiHomePage->notifyInventory->setText("[!]Database connection lost");
            return;
        }

        QString sqlQuery = "INSERT INTO Parts (Part_num, QTY, Part_name) "
                           "VALUES (\'"+partNum+"\',\'"+qty+"\',\'"+partName+"\');";


        if(sqlDB->query(sqlQuery))
        {
            uiHomePage->notifyInventory->setText("added part");
            fadeText("added part");
        }
        else
        {
            uiHomePage->notifyInventory->setText("part did not add");
            fadeText("part did not add");
        }
        return;
}

void HomePage::on_removeRecord_clicked()
{
    QString partNum = uiHomePage->del_partNum->text();

        if(!sqlDB->isOpen())
        {
            uiHomePage->notifyInventory->setText("[!]Database connection lost");
            return;
        }

        QString sqlQuery = "DELETE from Parts where Part_num = \'"+partNum+"\';";

        QString sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";

        if(sqlDB->query(sqlQuery))
        {
            uiHomePage->notifyInventory->setText("Deleted part");
            fadeText("Deleted Part");
        }
        else
        {
            uiHomePage->notifyInventory->setText("part does not exist");
            fadeText("part does not exist");
        }
        return;
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

void HomePage::fadeText(QString str)
{
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(uiHomePage->notifyInventory);
      uiHomePage->notifyInventory->setGraphicsEffect(effect);
      QPropertyAnimation* animation = new QPropertyAnimation(effect, "opacity");
      animation->setDuration(2000);
      animation->setStartValue(1.0);
      animation->setEndValue(0.0);
      animation->setEasingCurve(QEasingCurve::OutQuad);
      //connect(animation,SIGNAL(finished()),this,SLOT();
      animation->start(QAbstractAnimation::DeleteWhenStopped);
      uiHomePage->notifyInventory->show();
}

void HomePage::on_refreshInv_clicked()
{
    QSqlQueryModel* table;
    QString sqlQueryinv = "SELECT * FROM Parts";
    table = sqlDB->sqlTable(sqlQueryinv);
    displayInventory(table);
}

void HomePage::on_removeUser_clicked()
{

    QString removedUser =  uiHomePage->RemoveUserLineEdit->text();
    administration removeObj;
    removeObj.queryAdministration(removedUser);

    uiHomePage->showRemoved->setText("Removed \'" + removedUser +"\'");

}

void HomePage::on_AddUserButton_clicked()
{
    QString UID =  uiHomePage->UIDlineEdit->text();
    QString Fname =  uiHomePage->FNAMElineEdit->text();
    QString Lname =  uiHomePage->LNAMElineEdit->text();
    QString DOB =  uiHomePage->DOBlineEdit->text();
    QString Pass =  uiHomePage->PASSlineEdit->text();

    administration ADDObj;
    ADDObj.queryAddUser(UID,Fname,Lname,DOB,Pass);

    uiHomePage->Addedlabel->setText("Added \'" + Fname +"\'");
}
