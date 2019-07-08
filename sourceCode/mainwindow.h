#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Service/Service.h"
#include <QMessageBox>
#include "addTaskWindow.h"
#include <QFileDialog>
#include <QTableWidgetItem>


/**
    Search options for the tasks view table.
*/

enum TaskTableSearch{
    searchedByUser,
    searchedByProject,
    allTasks
};



/**
    Keeps the structure of the last search on the tasks view table.
*/

struct TaskTableState{
    TaskTableSearch tableSearch;
    QString searchCondition;
};





namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_addUserButton_clicked();

    void on_getAllUsersButton_clicked();

    void on_addTaskButton_clicked();

    void on_getTasksButton_clicked();

    void updateTaskTable();

    void on_deleteUserButton_clicked();

    void on_searchConditionComboBox_activated(const QString &arg1);

    void on_deleteTaskButton_clicked();

    void on_addProjectButton_clicked();

    void on_getAllProjectsButton_clicked();

    void on_deleteProjectButton_clicked();

    void on_actionOpen_triggered();



    void on_tasksTableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;

    AddTaskWindow* addTaskWindow;

    Service systemService;

    TaskTableState taskTableState; // keeps the structure of the last search on the tasks view table

    void showAllUsers();

    void showAllProjects();

    void showTaskList(QList<Task> list);

    void initTasksTab();



};

#endif // MAINWINDOW_H
