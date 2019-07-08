#include "Service/Service.h"


Service::Service()
{

}


void Service::initDB()
{
    DbConnector::initDB();
}


QList<User> Service::getAllUsers()
{
    return userDao.getAll();
}


void Service::addUser(QString name)
{    
    User user(name);
    userDao.addUser(user);
}


QList<Task> Service::getTasksByUser(QString userName)
{
    User user = userDao.getByName(userName);
    QList<Task> taskList = taskDao.getByUser(user);
    return  taskList;
}


QList<Task> Service::getTasksByProject(QString projectName)
{
    QList<Task> taskList;
    Project project = projectDao.getByName(projectName);
    taskList = taskDao.getByProject(project);
    return taskList;
}


QList<Task> Service::getAllTasks()
{
    QList<Task> taskList;
    taskList = taskDao.getAll();
    return taskList;
}


QList<Project> Service::getAllProjects()
{
    return projectDao.getAll();
}



void Service::addTask(QString topic, int priority, QString description, QString type, QString userName, QString projectName)
{
    User user = userDao.getByName(userName);
    Project project  = projectDao.getByName(projectName);
    Task task(user, topic, type, description, priority, project);
    taskDao.addTask(task);
}


void Service::deleteUser(QString name)
{
    User user = userDao.getByName(name);

    if(taskDao.hasUser(user))
        throw QString("User has a task. Deletion is prohibited.");

    userDao.deleteUser(user);
}


void Service::deleteTask(QString topic)
{
    Task task = taskDao.getByTopic(topic);
    taskDao.deleteTask(task);
}


void Service::deleteProject(QString name)
{
    Project project = projectDao.getByName(name);

    if(taskDao.hasProject(project))
        throw QString("Project has a task. Deletion is prohibited.");

    projectDao.deleteProject(project);
}


void Service::addProject(QString name)
{
    Project project(name);
    projectDao.add(project);
}



