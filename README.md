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

![tasks window](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/TasksWindow.PNG?raw=true)

All data is stored in SQLite database . User can select it's own .sqlite file (it should match the database scheme).

![select db](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/Open%20File.png?raw=true)

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
 
 ![filter](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/filter.png?raw=true)

It is not possible to delete a user or a project connected to a task.
![deletionErro](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/userDeleteError.PNG?raw=true)

Each task should have a unique topic.
![add task window](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/addTask.PNG?raw=true)


### Structure of the application
![structure](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/appStructure.PNG?raw=true)



