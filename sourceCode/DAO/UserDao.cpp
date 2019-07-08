#include "DAO/UserDao.h"

QList<User> UserDao::getAll()
{
    QList<User> list;

    QString query = "select * from user";

    QSqlQuery qry = executeQuery(query);

    while(qry.next())
    {
        QString name    = qry.value(1).toString();
        int id          = qry.value(0).toInt();
        list.append({name, id});
    }
    return list;
}


void UserDao::addUser(User user)
{
    QString query = "insert into user (name) values('" + QString(user.getName()) + "');";

    QSqlQuery qry = executeQuery(query);
}



User UserDao::getByName(QString name)
{
    QString query = "select * from user where name = '" + name + "';";

    QSqlQuery qry = executeQuery(query);

    qry.next();
    QString userName    = qry.value(1).toString();
    int id              = qry.value(0).toInt();
    User user(userName, id);
    return user;
}



void UserDao::deleteUser(User user)
{
    QString query = " delete from user where name = '" + user.getName() + "';";

    QSqlQuery qry = executeQuery(query);
}


