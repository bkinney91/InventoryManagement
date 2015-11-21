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
    QSqlQueryModel* getOutOfStockItems();
    QString getMTDOrderCost();
    QString getMTDSaleValue();
    QString getOverheadCost();
    QString getOverheadValue();
    QString sqlPath;
private:

      sqlDAL* sqlDB;            // Interface for the SQL Data Access Layer.
//signals:

//public slots:
};

#endif // DASHBOARDDAL_H
