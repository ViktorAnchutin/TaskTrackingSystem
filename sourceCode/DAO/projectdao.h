#ifndef PROJECTDAO_H
#define PROJECTDAO_H

#include "DAO/dao.h"


class ProjectDao : DAO
{

public:

    Project getByName(QString projectName);

    QList<Project> getAll();

    void add(Project project);

    void deleteProject(Project project);

};

#endif // PROJECTDAO_H
