#include "taskdao.h"


void TaskDao::addTask(Task task)
{
    QString query = "insert into tasks (topic, type, priority, user_id, project_id, description) "
                    "values ('" + task.getTopic() + "', '" + task.getType() + "', " + QString::number(task.getPriority())
                    + ", " + QString::number(task.getUser().getId()) + ", " + QString::number(task.getProject().getId())
                    + ", '" + task.getDescription() + "');";

    QSqlQuery qry = executeQuery(query);
}




QList<Task> TaskDao::getByUser(User user)
{
    QList<Task> taskList;

    QString query = "select user.id, user.name, tasks.id, tasks.topic, tasks.type, tasks.description, tasks.priority, projects.id, projects.name "
                    "from user inner join tasks on user.id = tasks.user_id inner join projects "
                    "on tasks.project_id = projects.id "
                    "where tasks.user_id = '" + QString::number(user.getId()) + "';";

    QSqlQuery qry = executeQuery(query);

    while(qry.next())
    {
        int userId              = qry.value(0).toInt();
        QString userName        = qry.value(1).toString();
        //int taskId              = qry.value(2).toInt();
        QString taskTopic       = qry.value(3).toString();
        QString taskType        = qry.value(4).toString();
        QString taskDescription = qry.value(5).toString();
        int taskPriority        = qry.value(6).toInt();
        int projectId           = qry.value(7).toInt();
        QString projectName     = qry.value(8).toString();

        User user(userName, userId);
        Project project(projectName, projectId);
        taskList.append({user, taskTopic, taskType, taskDescription, taskPriority, project});
     }
    return taskList;
}


QList<Task> TaskDao::getByProject(Project project)
{
    QList<Task> taskList;

    QString query = "select user.id, user.name, tasks.id, tasks.topic, tasks.type, tasks.description, tasks.priority, projects.id, projects.name "
                    "from user inner join tasks on user.id = tasks.user_id inner join projects "
                    "on tasks.project_id = projects.id "
                    "where tasks.project_id = '" + QString::number(project.getId()) + "';";

    QSqlQuery qry = executeQuery(query);

    while(qry.next())
    {
        int userId              = qry.value(0).toInt();
        QString userName        = qry.value(1).toString();
        //int taskId              = qry.value(2).toInt();
        QString taskTopic       = qry.value(3).toString();
        QString taskType        = qry.value(4).toString();
        QString taskDescription = qry.value(5).toString();
        int taskPriority        = qry.value(6).toInt();
        int projectId           = qry.value(7).toInt();
        QString projectName     = qry.value(8).toString();

        User user(userName, userId);
        Project project(projectName, projectId);
        taskList.append({user, taskTopic, taskType, taskDescription, taskPriority, project});
     }
    return taskList;
}

Task TaskDao::getByTopic(QString topic)
{

    QString query = "select user.id, user.name, tasks.id, tasks.topic, tasks.type, tasks.description, tasks.priority, projects.id, projects.name "
                    "from user inner join tasks on user.id = tasks.user_id inner join projects "
                    "on tasks.project_id = projects.id "
                    "where tasks.topic = '" + topic + "';";

    QSqlQuery qry = executeQuery(query);

    qry.next();

    int userId              = qry.value(0).toInt();
    QString userName        = qry.value(1).toString();
    //int taskId              = qry.value(2).toInt();
    QString taskTopic       = qry.value(3).toString();
    QString taskType        = qry.value(4).toString();
    QString taskDescription = qry.value(5).toString();
    int taskPriority        = qry.value(6).toInt();
    int projectId           = qry.value(7).toInt();
    QString projectName     = qry.value(8).toString();

    User user(userName, userId);
    Project project(projectName, projectId);

    return {user, taskTopic, taskType, taskDescription, taskPriority, project};
}



QList<Task> TaskDao::getAll()
{
    QList<Task> taskList;

    QString query = "select user.id, user.name, tasks.id, tasks.topic, tasks.type, tasks.description, tasks.priority, projects.id, projects.name "
                    "from user inner join tasks on user.id = tasks.user_id inner join projects "
                    "on tasks.project_id = projects.id; ";

    QSqlQuery qry = executeQuery(query);

    while(qry.next())
    {
        int userId              = qry.value(0).toInt();
        QString userName        = qry.value(1).toString();
        //int taskId              = qry.value(2).toInt();
        QString taskTopic       = qry.value(3).toString();
        QString taskType        = qry.value(4).toString();
        QString taskDescription = qry.value(5).toString();
        int taskPriority        = qry.value(6).toInt();
        int projectId           = qry.value(7).toInt();
        QString projectName     = qry.value(8).toString();

        User user(userName, userId);
        Project project(projectName, projectId);
        taskList.append({user, taskTopic, taskType, taskDescription, taskPriority, project});
     }
    return taskList;
}



void TaskDao::deleteTask(Task task)
{
    QString query = "delete from tasks where topic = '" + task.getTopic() + "';" ;

    QSqlQuery qry = executeQuery(query);
}



bool TaskDao::hasUser(User user)
{
    QString query = "select count(*) from tasks where user_id = " + QString::number(user.getId()) + ";";

    QSqlQuery qry = executeQuery(query);

    qry.next();
    if(qry.value(0)==0)
        return false;
    else
        return true;
}



bool TaskDao::hasProject(Project project)
{
    QString query = "select count(*) from tasks where project_id = " + QString::number(project.getId()) + ";";

    QSqlQuery qry = executeQuery(query);

    qry.next();
    if(qry.value(0)==0)
        return false;
    else
        return true;
}

