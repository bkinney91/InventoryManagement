// sqlDAL.h
//
// Author:      Massimo Cannavo
//
// Description: The implementation for the SQL Data Access Layer (DAL). The
//              Data Access Layer will create the interface for accessing the
//              database. Whenever the database needs to be queried, the DAL
//              will interface with the program and perform the specified
//              database operation.

#include "sqlDAL.h"

sqlDAL* sqlDAL::objSqlDAL = NULL; // Global single instance (singleton) of DAL.

// Returns the current instance of the Data Access Layer. If there is no
// current instance, returns a newly instantiated sqlDLA instance.
//
// Args:
//    sqlPath (QString): The path of the SQL database.
//
// Returns:
//    objSqlDAL (sqlDAL*): Single instance of the Data Access Layer.
sqlDAL* sqlDAL::getInstance(QString sqlPath)
{
    if(!objSqlDAL)
        objSqlDAL = new sqlDAL(sqlPath);

    return objSqlDAL;
}

// The constructor will define the SQL connection for the DAL.
//
// Args:
//    sqlPath (QString): The path of the SQL database.
sqlDAL::sqlDAL(QString sqlPath)
{
    sqlConnection = QSqlDatabase::addDatabase("QSQLITE");
    sqlConnection.setDatabaseName(sqlPath);
}
