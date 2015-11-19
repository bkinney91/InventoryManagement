#ifndef INVENTORY_H
#define INVENTORY_H

#include "sqlDAL.h"
#include "homepage.h"

class Inventory
{
public:
    Inventory(QString sqlPath) { sqlDB = sqlDAL::getInstance(sqlPath); }
    QSqlQueryModel* queryInventory();

private:
    sqlDAL* sqlDB;
};

#endif // INVENTORY_H
