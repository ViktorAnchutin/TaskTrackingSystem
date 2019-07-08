#ifndef ADDTASKWINDOW_H
#define ADDTASKWINDOW_H

#include <QMainWindow>
#include "Service/Service.h"
#include <QMessageBox>

namespace Ui {
class AddTaskWindow;
}

class AddTaskWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddTaskWindow(QWidget *parent = nullptr, Service* service = nullptr);
    ~AddTaskWindow();

signals:
    void updateTable();

private slots:
    void on_createTaskButton_clicked();

private:
    Ui::AddTaskWindow *ui;

    Service* systemService;
};

#endif // ADDTASKWINDOW_H
