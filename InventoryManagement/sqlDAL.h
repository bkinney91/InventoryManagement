// sqlDAL.h
//
// Author:      Massimo Cannavo
//
// Description: The header definition for the SQL Data Access Layer (DAL). The
//              Data Access Layer will create the interface for accessing the
//              database. Whenever the database needs to be queried, the DAL
//              will interface with the program and perform the specified
//              database operation.

#ifndef SQLDAL_H
#define SQLDAL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QVariant>
#include <QList>

// The Data Access Layer (DAL) instantiates the database connection. Once the
// connection has been established, the DAL will be used to read and update the
// database according to the data access model.
class sqlDAL
{
public:

    // Returns the current instance of the Data Access Layer. If there is no
    // current instance, returns a newly instantiated sqlDLA instance.
    //
    // Args:
    //    sqlPath (QString): The path of the SQL database.
    //
    // Returns:
    //    objSqlDAL (sqlDAL*): Single instance of the Data Access Layer.
    static sqlDAL* getInstance(QString sqlPath);

    // Attempt to connect to the SQL database.
    //
    // Returns:
    //    (bool): Denotes if the connection was established.
    bool connect() { if(!isOpen()) return sqlConnection.open(); else return true; }

    // Attempt to disconnect from the SQL database.
    void disconnect() { sqlConnection.close(); }

    // Determine if the SQL connection is open.
    //
    // Returns:
    //    (bool): Denotes if the SQL connection is open.
    bool isOpen() { return sqlConnection.isOpen(); }

    // Attempt to query the database with the specified SQL statement.
    //
    // Args:
    //    statement (QString): The SQL statement to query.
    //
    // Returns:
    //    (bool): Denotes if the query was executed.
    bool query(QString statement);

    // After the query is executed, the query is positioned on an invalid
    // record and must be navigated to a valid record before data values can
    // be retrieved by using next.
    //
    // Returns:
    //    (bool): Denotes if the record was able to be retrieved.
    bool result() { return sqlQuery.first(); }

    // Fetch the result of the query that was executed.
    //
    // Returns:
    //     (QList<QString>): A list of string values from the query result.
    QList<QString> next();

    //
    QSqlQueryModel* sqlTable(QString statement);

    // The destructor will terminate the database connection.
    ~sqlDAL() { if(isOpen()) disconnect(); }

private:
    static sqlDAL* objSqlDAL;   // Single instance (singleton) of DAL.
    QSqlDatabase sqlConnection; // Connection to the sql database.
    QSqlQuery sqlQuery;         // Interface for the SQL query.

    // The constructor will define the SQL connection for the DAL.
    //
    // Args:
    //    sqlPath (QString): The path of the SQL database.
    sqlDAL(QString sqlPath);
};

#endif
