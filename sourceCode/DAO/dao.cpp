#include "dao.h"



QSqlQuery DAO::executeQuery(QString query)
{
   if(!DbConnector::dataBase.isOpen())
       throw QString("DB is not opened!") ;

    QSqlQuery qry;

    if(!qry.exec(query))
        throw qry.lastError().databaseText();

    return qry;
}
