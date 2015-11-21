#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <qlist.h>
#include <part.h>
#include <dashboarddal.h>

class Dashboard
{
public:
    QList<Part> outOfStockItems;
    QSqlQueryModel *outOfStockTable;
    QString mtdOrdersCost;
    QString mtdSalesValue;
    QString overheadValue;
    QString overheadCost;
    QString overheadNet;
    static Dashboard* getDashboardInstance();

private:
    Dashboard();
    Dashboard(Dashboard const&);
    void operator=(Dashboard const&);

    static Dashboard* dashboardInstance;
};

#endif // DASHBOARD_H
