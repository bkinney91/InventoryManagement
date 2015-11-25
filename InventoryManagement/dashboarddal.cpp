#include "dashboarddal.h"
#include <QSqlQuery>
#include <qvariant.h>
#include "part.h"
#include <QList>
#include <sqlDAL.h>
#include <QApplication>

//Constructor for Dashboard
//Written by Bryce Kinney
dashboardDAL::dashboardDAL()
{
    sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";
    sqlDB = sqlDAL::getInstance(sqlPath);
}


//Retrieves the sum of the part_cost field for all orders for the current calendar month
//Written by Bryce Kinney
QString dashboardDAL::getMTDOrderCost()
{


    QString mtdOrderCost = "SELECT COUNT(part_cost) as MTDOrderValue FROM Orders WHERE strftime('%m', Order_date)= strftime('%m', 'now') AND  strftime('%Y', Order_date) = strftime('%Y', 'now')";
    if(sqlDB->query(mtdOrderCost) && sqlDB->result())
    {
       return sqlDB->next().at(0);
    }
    else
    {
        return "Error Connecting to database";
    }

}


//Retrieves the sum of the sale_price for all sales for the current calendar month
//Written by Bryce Kinney
QString dashboardDAL::getMTDSaleValue()
{

    QString mtdSaleValue = "SELECT COUNT(sale_price) as MTDSaleValue FROM Sales WHERE strftime('%m', Sale_date) = strftime('%m', 'now') AND  strftime('%Y', Sale_date) = strftime('%Y', 'now')";

    if(sqlDB->query(mtdSaleValue) && sqlDB->result())
    {
       return sqlDB->next().at(0);
    }
    else
    {
        return "Error Connecting to database";
    }
}

//Retrieves the sum of the sales_price for all of the in stock items
//Written by Bryce Kinney
QString dashboardDAL::getOverheadValue()
{

    QString overheadValue = "SELECT COUNT(Part_price) as OverheadValue FROM Parts WHERE Qty > 0";

    if(sqlDB->query(overheadValue) && sqlDB->result())
    {
       return sqlDB->next().at(0);
    }
    else
    {
        return "Error Connecting to database";
    }
}

//Retrieves the sum of the cost for all in stock items
//Written by Bryce Kinney
QString dashboardDAL::getOverheadCost()
{

    QString overheadCost = "SELECT COUNT(Part_cost) as OverheadCost FROM Parts WHERE QTY > 0";

    if(sqlDB->query(overheadCost) && sqlDB->result())
    {
       return sqlDB->next().at(0);
    }
    else
    {
        return "Error Connecting to database";
    }
}


//Gets list of all parts that have 0 in stock
//Written by Bryce Kinney
QSqlQueryModel* dashboardDAL::getOutOfStockItems()
{

    QSqlQueryModel* outOfStockTable;

    if(!sqlDB->isOpen())
        return outOfStockTable;

    QString sqlQuery = "Select Part_num, Part_name, Part_desc from Parts where Qty = 0";
    outOfStockTable = sqlDB->sqlTable(sqlQuery);

    return outOfStockTable;




    /*
     * QList<Part> outOfStockItems;
    QString outOfStockQuery = "Select Part_num, Part_name, Part_desc from Parts where Qty = 0";
    if(sqlDB->query(outOfStockQuery) && sqlDB->result())
    {
        QList<QString> queryList = sqlDB->next();
        while(!queryList.empty())
        {
           Part currentPart;
           currentPart.number = queryList.at(0);
           queryList.pop_front();
           currentPart.name =  queryList.at(0);
           queryList.pop_front();
           currentPart.description = queryList.at(0);
           queryList.pop_front();
           outOfStockItems.append(currentPart);
        }
    }
    return outOfStockItems;
    */
}
