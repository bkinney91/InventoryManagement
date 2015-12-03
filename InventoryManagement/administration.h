/*Author: Donovan Dsouza
This is the header file for the administration page where
the user can add and remove users.(more to be implemented if time
exsits.
*/


#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "sqlDAL.h"
#include "homepage.h"
#include "ui_homepage.h"

class administration
{

public:
    administration();
    administration(QString sqlPath) { sqlDB = sqlDAL::getInstance(sqlPath); }
    void queryAdministration(QString);
    void queryAddUser(QString,QString,QString,QString,QString);
    QString sqlPath;


private:
    sqlDAL* sqlDB;


};


#endif // ADMINISTRATION_H
