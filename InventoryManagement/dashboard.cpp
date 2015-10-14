#include "dashboard.h"
//Constructor for the dashboard class
//Written By Bryce Kinney
dashboard::dashboard()
{

    getMTDOrderCost();
    getMTDSaleValue();
}

//Retrieves the sum of the part_cost field for all orders for the current calendar month
//Written by Bryce Kinney
dashboard::getMTDOrderCost()
{
    QSqlQuery orderQuery;
    QString mtdOrderCost = "SELECT COUNT(part_cost) as MTDOrderValue FROM Orders WHERE strftime('%m', Order_date)"
            +"= strftime('%m', 'now') AND  strftime('%Y', Order_date) = strftime('%Y', 'now')";



    if(orderQuery.exec(mtdOrderCost) && orderQuery.next())
    {
        mtdOrdersCost = query.value(0);
    }

}
//Retrieves the sum of the sale_price for all sales for the current calendar month
//Written by Bryce Kinney
dashboard::getMTDSaleValue()
{
    QSqlQuery saleQuery;
    QString mtdSaleValue = "SELECT COUNT(sale_price) as MTDSaleValue FROM Sales WHERE strftime('%m', Sale_date)"
            +"= strftime('%m', 'now') AND  strftime('%Y', Sale_date) = strftime('%Y', 'now')";



    if(saleQuery.exec(mtdSaleValue) && saleQuery.next())
    {
        mtdSalesValue = query.value(0);
    }
}

