#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTasksTab();

    try {
        systemService.initDB();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_addUserButton_clicked()
{
    try {
        systemService.addUser(ui->lineEditUserName->text());
        ui->lineEditUserName->clear();
        showAllUsers();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
}


void MainWindow::on_getAllUsersButton_clicked()
{
    try {
        showAllUsers();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
}



void MainWindow::on_addTaskButton_clicked()
{
    addTaskWindow = new AddTaskWindow(this, &systemService);

    connect(addTaskWindow, SIGNAL(updateTable()), this, SLOT(updateTaskTable()));

    addTaskWindow->show();
}



void MainWindow::on_getTasksButton_clicked()
{
    QString searchCondition = ui->searchConditionComboBox->currentText();

    try {
        if(searchCondition == "all")
        {
            QList<Task> taskList;
            taskList = systemService.getAllTasks();
            showTaskList(taskList);

            taskTableState.tableSearch = allTasks; // save search parameter
        }
        else if(searchCondition == "by user")
        {

            QString userName = ui->searchParameterComboBox->currentText();
            QList<Task> list = systemService.getTasksByUser(userName);
            showTaskList(list);

            taskTableState.searchCondition = userName; // save search parameters
            taskTableState.tableSearch = searchedByUser;
        }
        else if(searchCondition == "by project")
        {

            QString projectName = ui->searchParameterComboBox->currentText();
            QList<Task> list = systemService.getTasksByProject(projectName);
            showTaskList(list);

            taskTableState.searchCondition = projectName; // save search parameters
            taskTableState.tableSearch = searchedByProject;
        }
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }

    ui->searchConditionComboBox->setCurrentIndex(0); // reset search condition. New search options have to be chosen explicitly to generate a signal to load a data to a ComboBox
    ui->searchParameterComboBox->clear();
}

void MainWindow::updateTaskTable()
{
    QList<Task> list;

    try {
        switch(taskTableState.tableSearch) // update based on last search structure
        {
            case allTasks:
            list = systemService.getAllTasks();
            break;

            case searchedByProject:
            list = systemService.getTasksByProject(taskTableState.searchCondition);
            break;

            case searchedByUser:
            list = systemService.getTasksByUser(taskTableState.searchCondition);
            break;
        }
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }

    showTaskList(list);
}


void MainWindow::showAllUsers()
{   
    QList<User> users = systemService.getAllUsers();
    ui->usersListWidget->clear();
    for(auto i : users)
    {
        ui->usersListWidget->addItem(i.getName());
    }

}

void MainWindow::showAllProjects()
{
    QList<Project> projects = systemService.getAllProjects();
    ui->projectsListWidget->clear();
    for(auto i : projects)
    {
        ui->projectsListWidget->addItem(i.getName());
    }
}

void MainWindow::showTaskList(QList<Task> list)
{
    ui->tasksTableWidget->clearContents();
    ui->tasksTableWidget->setRowCount(list.size());

    // fill in the table widget with data about tasks
    for(int i=0; i<list.size(); i++)
    {
       Task task = list.at(i);      
       ui->tasksTableWidget->setItem(i, 0, new QTableWidgetItem(task.getProject().getName()));
       ui->tasksTableWidget->setItem(i, 1, new QTableWidgetItem(task.getTopic()));
       ui->tasksTableWidget->setItem(i, 2, new QTableWidgetItem(task.getType()));
       ui->tasksTableWidget->setItem(i, 3, new QTableWidgetItem(task.getUser().getName()));
       ui->tasksTableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(task.getPriority())));
       ui->tasksTableWidget->setItem(i, 5, new QTableWidgetItem(task.getDescription()));
    }
}

void MainWindow::initTasksTab()
{
    ui->tasksTableWidget->setColumnCount(6);
    ui->tasksTableWidget->setHorizontalHeaderLabels({"Project","Topic","Type","User","Priority", "Description"});
    ui->tasksTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->searchConditionComboBox->addItem("all");
    ui->searchConditionComboBox->addItem("by user");
    ui->searchConditionComboBox->addItem("by project");
}



void MainWindow::on_deleteUserButton_clicked()
{

    // check if an item is selected
    QList<QListWidgetItem*> list = ui->usersListWidget->selectedItems();
    if(list.size() == 0)
    {
        QMessageBox::critical(this, "ERROR", "Select a user");
        return;
    }

    QString userName = ui->usersListWidget->currentItem()->text();

    try {
        systemService.deleteUser(userName);
        showAllUsers();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
}

void MainWindow::on_searchConditionComboBox_activated(const QString &arg1)
{
    ui->searchParameterComboBox->clear();

    try {
        if(arg1=="by user")
        {
            QList<User> userList = systemService.getAllUsers();
            for(auto user : userList)
            {
                ui->searchParameterComboBox->addItem(user.getName());
            }
        }
        else if(arg1=="by project")
        {
            QList<Project> projectList = systemService.getAllProjects();
            for(auto project : projectList)
            {
                ui->searchParameterComboBox->addItem(project.getName());
            }
        }
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }


}

void MainWindow::on_deleteTaskButton_clicked()
{
    int currentRow = ui->tasksTableWidget->currentRow();
    if(currentRow<0)
    {
        QMessageBox::critical(this, "ERROR", "You should choose a task to be deleted.");
        return;
    }
    QTableWidgetItem* taskTopic = ui->tasksTableWidget->item(currentRow, 1);
    try {
        systemService.deleteTask(taskTopic->text());
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
    updateTaskTable();
}

void MainWindow::on_addProjectButton_clicked()
{
    try {
        systemService.addProject(ui->projectNameLineEdit->text());
        ui->projectNameLineEdit->clear();
        showAllProjects();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
}

void MainWindow::on_getAllProjectsButton_clicked()
{
    try {
        showAllProjects();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
}

void MainWindow::on_deleteProjectButton_clicked()
{
    // check if item is selected
    QList<QListWidgetItem*> list = ui->projectsListWidget->selectedItems();
    if(list.size() == 0)
    {
        QMessageBox::critical(this, "ERROR", "Select a project");
        return;
    }

    QString projectName = ui->projectsListWidget->currentItem()->text();
    try {
        systemService.deleteProject(projectName);
        showAllProjects();
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open a file", QDir::currentPath(), "SQLite file (*.sqlite)");
    try {
         DbConnector::changeDB(fileName);
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }

}


/*
    Show cell data (usefull when the task description does not fit in the cell view)
*/

void MainWindow::on_tasksTableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    QMessageBox::information(this, "INFO", item->text());
}
