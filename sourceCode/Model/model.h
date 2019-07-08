#ifndef MODEL_HPP
#define MODEL_HPP


#include  <QList>
#include <QString>





class User;
class Task;
class Project;


class User{
private:

    int _Id;

    QString _name;


public:

   User(QString name);

   User(QString name, int id);   

   QString getName();

   int getId();

   void setId();
};










class Project{
private:

    int _Id;

    QString _name;

public:    

    Project(QString name);

    Project(QString name, int Id);

    int getId();

    QString getName();



};



class Task{
private:

    int _Id;

    User _user;

    QString _topic;

    QString _type;

    Project _project;

    QString _desciption;

    int _priority = 0;

public:    

    Task(User user, QString topic, QString type, QString description, int priority, Project project);

    QString getTopic();

    User getUser();

    Project getProject();

    void setUser(User user);

    QString getType();

    int getPriority();

    QString getDescription();

    int getId();

    void setId(int Id);

};










#endif // MODEL_HPP

