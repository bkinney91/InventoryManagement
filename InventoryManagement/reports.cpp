/*Author: Donovan Dsouza
 * this is the reports page that will use a drop down list of reports to generate
 * data on screen to the user.(additional funtion if time add a save to file option
 * */

#include "reports.h"


Reports::Reports(){

}

QSqlQueryModel* Reports::queryReports(QString reportType)
{
    QSqlQueryModel* table1;


    QString sqlQuery = "SELECT * FROM Users";
    table1 = sqlDB->sqlTable(sqlQuery);
     return table1;


    if(!sqlDB->isOpen())
        return table1;

    if(reportType== "User Report")
    {

    QString sqlQuery = "SELECT * FROM Users";
    table1 = sqlDB->sqlTable(sqlQuery);
     return table1;
    }

    if(reportType== "Order Report")
    {
     QString sqlQuery = "SELECT * FROM Orders";
     table1 = sqlDB->sqlTable(sqlQuery);
     return table1;
    }



    return table1;
}

