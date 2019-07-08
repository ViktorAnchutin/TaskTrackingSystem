#include "Model/model.h"



Project::Project(QString name)
{
    _name = name;
}

Project::Project(QString name, int Id)
{
    _name = name;
    _Id = Id;
}

int Project::getId()
{
    return _Id;
}

QString Project::getName()
{
    return _name;
}
