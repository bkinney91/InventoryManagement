#include "DashboardDAL.h"
#include <QSqlQuery>
#include <qstring.h>
#include <QVariant>
#include <string>
DashboardDAL::DashboardDAL()
{
    getMTDOrderCost();
    getMTDSaleValue();
    getOverheadValue();
    getOverheadCost();
    getOverheadNet();
}

//Retrieves the sum of the part_cost field for all orders for the current calendar month
//Written by Bryce Kinney
void DashboardDAL::getMTDOrderCost()
{
    QSqlQuery orderQuery;
    QString mtdOrderCost = "SELECT COUNT(part_cost) as MTDOrderValue FROM Orders WHERE strftime('%m', Order_date)= strftime('%m', 'now') AND  strftime('%Y', Order_date) = strftime('%Y', 'now')";



    if(orderQuery.exec(mtdOrderCost) && orderQuery.next())
    {
        mtdOrdersCost = orderQuery.value(0).toFloat();
    }

}


//Retrieves the sum of the sale_price for all sales for the current calendar month
//Written by Bryce Kinney
void DashboardDAL::getMTDSaleValue()
{
    QSqlQuery saleQuery;
    QString mtdSaleValue = "SELECT COUNT(sale_price) as MTDSaleValue FROM Sales WHERE strftime('%m', Sale_date) = strftime('%m', 'now') AND  strftime('%Y', Sale_date) = strftime('%Y', 'now')";



    if(saleQuery.exec(mtdSaleValue) && saleQuery.next())
    {
        mtdSalesValue = saleQuery.value(0).toFloat();
    }
}

//Retrieves the sum of the sales_price for all of the in stock items
//Written by Bryce Kinney
void DashboardDAL::getOverheadValue()
{
    QSqlQuery overheadValueQuery;
    QString overheadValueQString = "SELECT COUNT(Part_price) as OverheadValue FROM Parts WHERE Qty > 0";



    if(overheadValueQuery.exec(overheadValueQString) && overheadValueQuery.next())
    {
        overheadValue = overheadValueQuery.value(0).toFloat();
    }
}

//Retrieves the sum of the cost for all in stock items
//Written by Bryce Kinney
void DashboardDAL::getOverheadCost()
{
    QSqlQuery overheadCostQuery;
    QString overheadCostQString = "SELECT COUNT(Part_cost) as OverheadCost FROM Sales WHERE Quantity > 0";



    if(overheadCostQuery.exec(overheadCostQString) && overheadCostQuery.next())
    {
        overheadCost = overheadCostQuery.value(0).toFloat();
    }
}

//Written by Bryce Kinney
void DashboardDAL::getOverheadNet()
{
    overheadNet = overheadValue - overheadCost;
}

void DashboardDAL::getOutOfStockItems()
{
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


}
