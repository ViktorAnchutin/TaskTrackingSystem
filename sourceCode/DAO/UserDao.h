#ifndef USER_DAO_HPP
#define USER_DAO_HPP

#include "DAO/dao.h"

class UserDao : DAO
{

public:
    QList<User> getAll();

    void addUser(User user);

    User getByName(QString name);

    void deleteUser(User user);
};


#endif // USER_DAO_HPP
