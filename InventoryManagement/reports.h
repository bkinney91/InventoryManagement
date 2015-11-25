/*Author: Donovan Dsouza
This is the header file for the reports page where the user
can select reports from a drop down and use them to generate results.
*/


#ifndef REPORTS_H
#define REPORTS_H

#include "sqlDAL.h"
#include "homepage.h"
#include "ui_homepage.h"

class Reports
{

public:
    Reports();
    Reports(QString sqlPath) { sqlDB = sqlDAL::getInstance(sqlPath); }
    QSqlQueryModel* queryReports(QString);
    QString sqlPath;


private:
    sqlDAL* sqlDB;

    QString* value;
};


#endif // REPORTS_H
