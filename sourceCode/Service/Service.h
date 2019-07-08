#ifndef SERVICE_H
#define SERVICE_H


#include "DAO/UserDao.h"
#include "DAO/taskdao.h"
#include "DAO/projectdao.h"



class Service {

private:

    UserDao userDao;

    TaskDao taskDao;

    ProjectDao projectDao;

public:

   Service();

   void initDB();

   QList<User> getAllUsers();

   QList<Task> getAllTasks();

   QList<Project> getAllProjects();   

   QList<Task> getTasksByUser(QString userName);

   QList<Task> getTasksByProject(QString projectName);

   void deleteUser(QString name);

   void deleteTask(QString topic);

   void deleteProject(QString name);

   void addProject(QString name);

   void addUser(QString name);

   void addTask(QString topic, int priority, QString description, QString type, QString userName, QString projectName);

};


#endif //SERVICE_H
