#include "Model/model.h"

User::User(QString name)
{
    _name = name;
}


User::User(QString name, int id)
{
    _name = name;
    _Id = id;
}


QString User::getName()
{
    return _name;
}


int User::getId()
{
    return _Id;
}
