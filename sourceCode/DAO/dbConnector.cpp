#include "DAO/dbConnector.h"

QSqlDatabase DbConnector::dataBase;
QString DbConnector::dbName;
QString DbConnector::dbPATH;


void DbConnector::enableForeingKeys()
{
    if(!dataBase.isOpen())
   {
       throw QString("Failed to open the dataBase! ") ;
   }

   QSqlQuery qry;

   QString query = "PRAGMA foreign_keys = ON;" ;

   if(!qry.exec(query))
        throw qry.lastError().databaseText();
}


void DbConnector::initDB()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dbName = "db.sqlite";
    dbPATH = QDir::currentPath() + "/" + dbName;
    dataBase.setDatabaseName(dbPATH);

    if(!dataBase.open())
       throw QString("Error opening " + dataBase.databaseName());

    enableForeingKeys();
}

void DbConnector::changeDB(QString path)
{
    dataBase.close();

    dataBase.setDatabaseName(path);

    if(!dataBase.open())
       throw QString("Error opening " + dataBase.databaseName());

    enableForeingKeys();
}
