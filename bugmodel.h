#ifndef BUGMODEL_H
#define BUGMODEL_H

#include <QtSql>
#include "db.h"
#include "bugobject.h"
#include "taskobject.h"

using namespace std;

class bugModel
{
    public:
        bugModel();
        vector<bugObject> fetchObjectsBy(taskObject task);
        vector<bugObject> objects;
        bool addBug(taskObject task, QString content);
        bool removeBug(bugObject bug);
};

#endif // BUGMODEL_H
