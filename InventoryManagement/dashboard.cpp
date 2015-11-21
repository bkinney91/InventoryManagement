#include "dashboard.h"
#include "dashboarddal.h"
#include <QSqlQuery>
#include <qstring.h>
#include <QVariant>
#include <string>

Dashboard* Dashboard::dashboardInstance = NULL;

Dashboard* Dashboard::getDashboardInstance()
{
    if(!dashboardInstance)
        dashboardInstance = new Dashboard();

    return dashboardInstance;
}

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

