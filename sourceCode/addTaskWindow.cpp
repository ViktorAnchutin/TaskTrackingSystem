#include "addTaskWindow.h"
#include "ui_addTaskWindow.h"

AddTaskWindow::AddTaskWindow(QWidget *parent, Service* service) :
    QMainWindow(parent),
    ui(new Ui::AddTaskWindow),
    systemService(service)
{
    ui->setupUi(this);

    try {
        QList<User> userList = systemService->getAllUsers();
        for(auto user : userList)
        {
            ui->usersComboBox->addItem(user.getName());
        }

        QList<Project> projectList = systemService->getAllProjects();
        for(auto project : projectList)
        {
            ui->projectsComboBox->addItem(project.getName());
        }
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }

    ui->priorityComboBox->addItem(QString::number(0));
    ui->priorityComboBox->addItem(QString::number(1));
    ui->priorityComboBox->addItem(QString::number(2));
    ui->priorityComboBox->addItem(QString::number(3));
    ui->priorityComboBox->addItem(QString::number(4));

    ui->typeComboBox->addItem("Planning");
    ui->typeComboBox->addItem("Reactionary");
    ui->typeComboBox->addItem("Procedural");




}


AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}

void AddTaskWindow::on_createTaskButton_clicked()
{
    QString topic = ui->topicLineEdit->text();
    QString userName = ui->usersComboBox->currentText();
    QString projectName = ui->projectsComboBox->currentText();
    QString type = ui->typeComboBox->currentText();
    int priority = ui->priorityComboBox->currentText().toInt();
    QString description = ui->descriptionTextEdit->toPlainText();

    try {
        systemService->addTask(topic, priority, description, type, userName, projectName);
    } catch (QString e) {
        QMessageBox::critical(this, "ERROR", e);
    }

   emit updateTable();


}
