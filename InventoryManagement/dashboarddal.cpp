#include "dashboarddal.h"
#include <QSqlQuery>
#include <qvariant.h>
#include "part.h"
#include <QList>
#include <sqlDAL.h>
#include <QApplication>
dashboardDAL::dashboardDAL()
{
    sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";
}


//Retrieves the sum of the part_cost field for all orders for the current calendar month
//Written by Bryce Kinney
float dashboardDAL::getMTDOrderCost()
{
    QString mtdOrderCost = "SELECT COUNT(part_cost) as MTDOrderValue FROM Orders WHERE strftime('%m', Order_date)= strftime('%m', 'now') AND  strftime('%Y', Order_date) = strftime('%Y', 'now')";
    sqlDAL* sql = sqlDAL::getInstance(sqlPath);

    QSqlQuery temp = sql->result();
    if(sql->query(mtdOrderCost))
    {

       return temp.value(0).toFloat();
    }
    else
    {
        return -1;
    }

}


//Retrieves the sum of the sale_price for all sales for the current calendar month
//Written by Bryce Kinney
float dashboardDAL::getMTDSaleValue()
{
    QSqlQuery saleQuery;
    QString mtdSaleValue = "SELECT COUNT(sale_price) as MTDSaleValue FROM Sales WHERE strftime('%m', Sale_date) = strftime('%m', 'now') AND  strftime('%Y', Sale_date) = strftime('%Y', 'now')";



    if(saleQuery.exec(mtdSaleValue) && saleQuery.next())
    {
        return saleQuery.value(0).toFloat();
    }
    return -1;
}

//Retrieves the sum of the sales_price for all of the in stock items
//Written by Bryce Kinney
float dashboardDAL::getOverheadValue()
{
    QSqlQuery overheadValueQuery;
    QString overheadValueQString = "SELECT COUNT(Part_price) as OverheadValue FROM Parts WHERE Qty > 0";



    if(overheadValueQuery.exec(overheadValueQString) && overheadValueQuery.next())
    {
        return overheadValueQuery.value(0).toFloat();
    }
    return -1;
}

//Retrieves the sum of the cost for all in stock items
//Written by Bryce Kinney
float dashboardDAL::getOverheadCost()
{
    QSqlQuery overheadCostQuery;
    QString overheadCostQString = "SELECT COUNT(Part_cost) as OverheadCost FROM Sales WHERE Quantity > 0";



    if(overheadCostQuery.exec(overheadCostQString) && overheadCostQuery.next())
    {
        return overheadCostQuery.value(0).toFloat();
    }
    return -1;
}




QList<Part> dashboardDAL::getOutOfStockItems()
{
    QList<Part> outOfStockItems;
    QSqlQuery outOfStockQuery;
    QString outOfStockQString = "Select Part_num, Part_name, Part_desc from Parts where Qty = 0";
    if(outOfStockQuery.exec(outOfStockQString))
    {
        while(outOfStockQuery.next())
        {
           Part currentPart;
           currentPart.number = outOfStockQuery.value(0).toInt();
           currentPart.name = outOfStockQuery.value(1).toString();
           currentPart.description = outOfStockQuery.value(2).toString();
           outOfStockItems.append(currentPart);
        }
    }
    return outOfStockItems;


}
