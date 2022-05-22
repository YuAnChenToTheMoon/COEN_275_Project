#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projectmodel.h"
#include "projectobject.h"
#include "taskmodel.h"
#include "bugmodel.h"
#include "timelinemodel.h"
#include "user.h"
#include "usermodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (auth().signUp("123","456")){
        qDebug() << "Signed up successfully!";
    }
    else{
        qDebug() << "This user name already exisits!";
    }

    qDebug() << "Login:\n";
    user *usr = user::getInstance();
    if(usr->initUserWithAuth("test", "test")){
        qDebug() << usr->userName << "\n"
                 << usr->position << "\n"
                 << usr->userID << "\n"
                 << usr->posID << "\n\n";
    }
    else{
        qDebug() << "Failed to login\n";
    }

    if (userModel().addPosition(*usr, "employee")){
        qDebug() << "Added the position successfully!";
    }

    projectModel().addProject("Project D");
    qDebug() << "Fetch users:\n";
    vector<user> users = userModel().fetchObjectsBy("manager");
    for (auto item = users.begin(); item != users.end(); item++)
    {
        user new_user = *item;
        qDebug() << new_user.posID << "\n"
                 << new_user.position << "\n"
                 << new_user.userName << "\n";
    }


    qDebug() << "Fetch tasks by owner:\n";
//    vector<taskObject> tasks = taskModel().fetchObjectsBy(*usr);
    vector<taskObject> tasks = taskModel().fetchObjectsBy(*usr, "New");
    for (auto item = tasks.begin(); item != tasks.end(); item++)
    {
        taskObject task = *item;
        qDebug() << task.projectID << "\n"
                 << task.projectObject::name << "\n"
                 << task.projectObject::status << "\n"
                 << task.projectObject::createDate.toString() << "\n"
                 << task.projectObject::updateDate.toString() << "\n"
                 << task.taskID << "\n"
                 << task.name << "\n"
                 << task.status << "\n"
                 << task.createDate.toString() << "\n"
                 << task.updateDate.toString() << "\n\n";
    }

    vector<taskObject> othertasks = taskModel().fetchAllObjects();
    qDebug() << "All Other Tasks:\n";
    for (auto item = othertasks.begin(); item != othertasks.end(); item++)
    {
        taskObject task = *item;
        qDebug() << task.taskID << "\n"
                 << task.name << "\n"
                 <<"owner:"<< task.owner << "\n"
                 << task.status << "\n"
                 << task.createDate.toString() << "\n"
                 << task.updateDate.toString() << "\n\n";
         qDebug()<<task.assignTask(*usr);
    }

    vector<projectObject> projects = projectModel().fetchAllObjects();
    for (auto item = projects.begin(); item != projects.end(); item++)
    {
        projectObject project = *item;
        qDebug() << project.projectID << " Project Timeline:\n";
        project.updateProject("In progress");
        vector<timelineObject> timelines = timelineModel().fetchObjectsBy(project);
        for (auto item = timelines.begin(); item != timelines.end(); item++)
        {
            timelineObject timeline = *item;
            qDebug() << timeline.timelineID << "\n"
                    << timeline.name << "\n"
                    << timeline.status << "\n"
                    << timeline.startDate.toString() << "\n"
                    << timeline.endDate.toString() << "\n";
        }


        taskModel().addTask(project, "GOGOGO");

        vector<taskObject> tasks = taskModel().fetchObjectsBy(project);
        qDebug() << project.projectID << " Project and Tasks:\n";
        for (auto item = tasks.begin(); item != tasks.end(); item++)
        {
            taskObject task = *item;
            qDebug() << task.projectID << "\n"
                     << task.projectObject::name << "\n"
                     << task.projectObject::status << "\n"
                     << task.projectObject::createDate.toString() << "\n"
                     << task.projectObject::updateDate.toString() << "\n"
                     << task.taskID << "\n"
                     << task.name << "\n"
                     <<"owner:"<< task.owner << "\n"
                     << task.status << "\n"
                     << task.createDate.toString() << "\n"
                     << task.updateDate.toString() << "\n";
            qDebug()<<"TaskID: "<<task.taskID<<"\n";
            if(task.taskID == 3)
            {
                taskModel().removeTask(task);
            }

            qDebug() << "Bugs:\n";
            bugModel().addBug(task, "Not work");
            vector<bugObject> bugs = bugModel().fetchObjectsBy(task);
            for (auto item = bugs.begin(); item != bugs.end(); item++){
                bugObject bug = *item;
                qDebug() << bug.bugID << "\n"
               <<"name: "<< bug.name << "\n"
                         << bug.status << "\n"
                         << bug.createDate.toString() << "\n"
                         << bug.updateDate.toString() << "\n";
            }


        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

