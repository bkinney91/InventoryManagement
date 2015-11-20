#ifndef DASHBOARDDAL_H
#define DASHBOARDDAL_H
#include <QList>
#include <Part.h>
#include <sqlDAL.h>
#include <QSqlDatabase>
#include <QSqlQuery>
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
    QSqlDatabase sqlConnection;
private:


//signals:

//public slots:
};

#endif // DASHBOARDDAL_H
