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

All data is stored in SQLite database . User can select it's own .sqlite file (it must match the database scheme). By default file "db.sqlite" is selected.

![select db](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/Open%20File.png?raw=true)

Tables scheme:
- "tasks" table 
```
CREATE TABLE tasks (id INTEGER PRIMARY KEY,
   topic VARCHAR(20) UNIQUE NOT NULL,
    type VARCHAR(20) NOT NULL,
    priority INTEGER,
    user_id INTEGER,
    project_id INTEGER,
    description VARCHAR(150),
    FOREIGN KEY(user_id) REFERENCES user(id),
    FOREIGN KEY(project_id) REFERENCES projects(id)
    );
 ```
- "user" table
```
CREATE TABLE user (id INTEGER PRIMARY KEY, name VARCHAR(20) UNIQUE NOT NULL);
```

- "projects" table
```
CREATE TABLE projects (id INTEGER PRIMARY KEY, name VARCHAR(20) UNIQUE NOT NULL);
 ```
 
 Tasks can be filtered by project and by user.
 
 ![filter](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/Filter.png?raw=true)

It is not possible to delete a user or a project connected to a task.
![deletionErro](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/userDeleteError.PNG?raw=true)

Each task must have a unique topic.
![add task window](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/addTask.PNG?raw=true)

Each user and project must have a unique name.
![unique name](https://github.com/ViktorAnchutin/TaskTrackingSystem/blob/master/Images/Unique%20Name.png?raw=true)






