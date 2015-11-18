#ifndef DASHBOARDDAL_H
#define DASHBOARDDAL_H
#include <QList>
#include <Part.h>
#include <sqlDAL.h>

class dashboardDAL
{

public:
    dashboardDAL();
    QList<Part> getOutOfStockItems();
    float getMTDOrderCost();
    float getMTDSaleValue();
    float getOverheadCost();
    float getOverheadValue();
    QString sqlPath;
private:

//signals:

//public slots:
};

#endif // DASHBOARDDAL_H
