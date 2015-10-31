#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <qlist.h>
#include <part.h>

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
    void getOutOfStockItems();
    void getMTDOrderCost();
    void getMTDSaleValue();
    void getOverheadNet();
    void getOverheadCost();
    void getOverheadValue();

private:
    Dashboard();
    Dashboard(Dashboard const&);
    void operator=(Dashboard const&);

    static Dashboard* dashboardInstance;
};

#endif // DASHBOARD_H
