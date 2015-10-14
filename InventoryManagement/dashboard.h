#ifndef DASHBOARD_H
#define DASHBOARD_H


class dashboard
{
public:
    decimal mtdOrdersCost;
    decimal mtdSalesValue;
    decimal overheadValue;
    decimal overHeadCost;
    decimal overHeadNet;
    QList<Inventory> outOfStockItems();
    dashboard();
    void getMTDOrderCost();
    void getMTDSaleValue();
signals:

public slots:
};

#endif // DASHBOARD_H
