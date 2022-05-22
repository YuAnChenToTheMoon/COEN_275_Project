#ifndef TASKMODEL_H
#define TASKMODEL_H

#include "taskobject.h"
#include "projectobject.h"
#include "user.h"

using namespace std;

class taskModel
{
    public:
        taskModel();
        vector<taskObject> fetchAllObjects();
        vector<taskObject> fetchObjectsBy(projectObject project);
        vector<taskObject> fetchObjectsBy(user usr);
        vector<taskObject> fetchObjectsBy(user usr, QString curStatus);
        bool addTask(projectObject task, QString content);
        bool removeTask(taskObject task);
        vector<taskObject> objects;
};

#endif // TASKMODEL_H
