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
    overheadNet = overheadValue - overheadCost;
}

