#include "inventory.h"

QSqlQueryModel* Inventory::queryInventory()
{
    QSqlQueryModel* table;

    if(!sqlDB->isOpen())
        return table;

    QString sqlQuery = "SELECT * FROM Parts";
    table = sqlDB->sqlTable(sqlQuery);

    return table;
}
