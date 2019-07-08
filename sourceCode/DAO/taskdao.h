#ifndef TASKDAO_H
#define TASKDAO_H

#include "DAO/dao.h"

class TaskDao : DAO
{
private:

public:

    void addTask(Task task);

    QList<Task> getByUser(User user);

    QList<Task> getByProject(Project project);

    Task getByTopic(QString topic);

    QList<Task> getAll();

    void deleteTask(Task task);

    bool hasUser(User user);

    bool hasProject(Project project);

};

#endif // TASKDAO_H
