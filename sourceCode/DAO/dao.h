#ifndef DAO_H
#define DAO_H

#include "Model/model.h"
#include <QtSql>
#include <QtDebug>
#include "DAO/dbConnector.h"


/**
    Base class for Dao layer classes.
*/

class DAO
{
protected:
    QSqlQuery executeQuery(QString query);
};

#endif // DAO_H
