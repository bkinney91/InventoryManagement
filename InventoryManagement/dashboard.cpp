#include "dashboard.h"
#include "dashboarddal.h"
#include <QSqlQuery>
#include <qstring.h>
#include <QVariant>
#include <string>



Dashboard* Dashboard::dashboardInstance = NULL;

//Gives pointer to a dashboard instance
//Uses Singleton design pattern
//Written by Bryce Kinney
Dashboard* Dashboard::getDashboardInstance()
{
    if(!dashboardInstance)
        dashboardInstance = new Dashboard();

    return dashboardInstance;
}
//Dashboard constructor
//Set to private for Singleton Design Pattern
//Creates instance of Data Access Layer for the dashboard
//and executes all functions to populate data members
//Written by Bryce Kinney
Dashboard::Dashboard()
{
    dashboardDAL dataAccessLayer;
    mtdOrdersCost = dataAccessLayer.getMTDOrderCost();
    mtdSalesValue = dataAccessLayer.getMTDSaleValue();
    overheadValue = dataAccessLayer.getOverheadValue();
    overheadCost = dataAccessLayer.getOverheadCost();
    float net = overheadValue.toFloat() - overheadCost.toFloat();
    overheadNet = QString::number(net);
    //outOfStockItems = dataAccessLayer.getOutOfStockItems();
    outOfStockTable = dataAccessLayer.getOutOfStockItems();

}

