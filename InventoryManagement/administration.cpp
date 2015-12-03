
/*Author: Donovan Dsouza
 * This page serves to add and remove users. if time exists will add more functionality.
 *
 * */

#include "administration.h"
#include "homepage.h"
#include "ui_homepage.h"

administration::administration()
{
    sqlPath = qApp->applicationDirPath() + "/sql/db.sqlite3";
    sqlDB = sqlDAL::getInstance(sqlPath);
}

void administration::queryAdministration(QString userRemoved)
{



    if(!sqlDB->isOpen())
        return;


    QString sqlQuery = "DELETE FROM Users WHERE FNAME=\'" + userRemoved +"\'";
    sqlDB->sqlTable(sqlQuery);




    return;
}

void administration::queryAddUser(QString ID,QString Fname,QString Lname,QString DOB,QString Pass)
{



    if(!sqlDB->isOpen())
        return;


    QString sqlQuery = "INSERT INTO Users(User_ID,FNAME,LName,DOB,Password)VALUES('"+ID+"','"+Fname+"','"+Lname+"','"+DOB+"','"+Pass+"')";
    sqlDB->sqlTable(sqlQuery);




    return;
}
