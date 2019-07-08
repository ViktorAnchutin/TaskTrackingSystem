#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H


#include "Model/model.h"
#include <QtSql>


class DbConnector
{
private:
    static void enableForeingKeys();
    static QString dbPATH;
    static QString dbName;

public:
    static void initDB();                   // connects to the default DB file
    static void changeDB(QString path);
    static QSqlDatabase dataBase;

};


#endif // DBCONNECTOR_H

