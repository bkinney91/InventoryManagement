#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <qlist.h>
#include <part.h>
#include <dashboarddal.h>

class Dashboard
{
public:
    QList<Part> outOfStockItems;
    float mtdOrdersCost;
    float mtdSalesValue;
    float overheadValue;
    float overheadCost;
    float overheadNet;
    static Dashboard* getDashboardInstance();

private:
    Dashboard();
    Dashboard(Dashboard const&);
    void operator=(Dashboard const&);

    static Dashboard* dashboardInstance;
};

#endif // DASHBOARD_H
