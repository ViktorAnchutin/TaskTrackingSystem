# TaskTrackingSystem
Test Qt application working with SQLite database.


Application provides a basic functionality for managing tasks, users and projects (creation, deletion).

Each task has following attributes:  
 - Project
 - Type
 - Priority
 - Topic
 - User
 - Description

(%picture of the tasks window%)

All data is stored in SQLite database . User can select it's own .sqlite file (it should match the database scheme).

Tables scheme:
- "task" table 
```
create table tasks (id integer primary key,
   topic varchar(20) unique not null,
    type varchar(20) not null,
    priority integer,
    user_id integer,
    project_id integer,
    description varchar(150),
    foreign key(user_id) references user(id),
    foreign key(project_id) references projects(id)
    );
 ```
- "user" table
```
CREATE TABLE user (id integer primary key, name varchar(20) UNIQUE);
```

- "projects" table
```
CREATE TABLE projects (id integer primary key not null, name varchar(20) unique not null);
 ```
 
 Tasks can be filtered by project and by user.
 (%    %)

It is not possible to delete a user or a project connected to a task.
(% %)

Each task has to have a unique topic.


### Structure of the application
(% %)



