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
    if(!objSqlDAL && !sqlPath.isEmpty())
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

// Attempt to query the database with the specified SQL statement.
//
// Args:
//    statement (QString): The SQL statement to query.
//
// Returns:
//    (bool): Denotes if the query was executed.
bool sqlDAL::query(QString statement)
{
    QSqlQuery sqlQuery(sqlConnection);
    this->sqlQuery = sqlQuery;

    return this->sqlQuery.exec(statement);
}

// Fetch the result of the query that was executed.
//
// Returns:
//     (QList<QString>): A list of string values from the query result.
QList<QString> sqlDAL::next()
{
    QSqlRecord record = sqlQuery.record();
    QList<QString> queryResult;

    for(int i = 0; i < record.count(); ++i)
        queryResult.append(record.value(i).toString());

    while(sqlQuery.next())
    {
        record = sqlQuery.record();

        for(int i = 0; i < record.count(); ++i)
            queryResult.append(record.value(i).toString());
    }

    return queryResult;
}

//
QSqlQueryModel* sqlDAL::sqlTable(QString statement)
{
    QSqlQueryModel* table = new QSqlQueryModel();
    QSqlQuery sqlQuery(sqlConnection);

    sqlQuery.prepare(statement);
    sqlQuery.exec();
    table->setQuery(sqlQuery);

    return table;
}
