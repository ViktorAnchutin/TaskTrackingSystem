#include "Model/model.h"


Task::Task(User user, QString topic, QString type, QString description, int priority, Project project) :
    _user(user),
    _topic(topic),
    _type(type),
    _project(project),
    _desciption(description)
{
    _priority = priority;
}


QString Task::getTopic()
{
    return _topic;
}


User Task::getUser()
{
    return _user;
}


Project Task::getProject()
{
    return _project;
}


void Task::setUser(User user)
{
    _user = user;
}

QString Task::getType()
{
    return _type;
}


int Task::getPriority()
{
    return _priority;
}


QString Task::getDescription()
{
    return _desciption;
}


int Task::getId()
{
    return _Id;
}


void Task::setId(int Id)
{
    _Id = Id;
}
