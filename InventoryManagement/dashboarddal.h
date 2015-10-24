#ifndef DASHBOARDDAL_H
#define DASHBOARDDAL_H
#include <qlist.h>
#include <part.h>
class DashboardDAL
{
public:
    static DashboardDAL& getDashboardDALInstance();

    void getOutOfStockItems();
    float mtdOrdersCost;
    float mtdSalesValue;
    float overheadValue;
    float overheadCost;
    float overheadNet;
    QList<Part> outOfStockItems;
    void getMTDOrderCost();
    void getMTDSaleValue();
    void getOverheadNet();
    void getOverheadCost();
    void getOverheadValue();


private:
    DashboardDAL();
    DashboardDAL(DashboardDAL const&);
    void operator=(DashboardDAL const&);
};

#endif // DASHBOARDDAL_H
