#include "projectdao.h"


Project ProjectDao::getByName(QString projectName)
{
    QString query = "SELECT * FROM projects WHERE name = '" + projectName + "';";

    QSqlQuery qry = executeQuery(query);

    qry.next();
    int id = qry.value(0).toInt();
    Project project(projectName, id);
    return project;
}


QList<Project> ProjectDao::getAll()
{
    QList<Project> list;

    QString query = "select * from projects";

    QSqlQuery qry = executeQuery(query);

    while(qry.next())
    {
        QString name    = qry.value(1).toString();
        int id          = qry.value(0).toInt();
        list.append({name, id});
    }
    return list;
}


void ProjectDao::add(Project project)
{
    QString query = "insert into projects (name) values('" + QString(project.getName()) + "');";

    QSqlQuery qry = executeQuery(query);
}


void ProjectDao::deleteProject(Project project)
{
    QString query = " delete from projects where name = '" + project.getName() + "';";

    QSqlQuery qry = executeQuery(query);
}

