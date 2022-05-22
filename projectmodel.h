#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QtSql>
#include "db.h"
#include "projectobject.h"

using namespace std;

class projectModel
{
    public:
        projectModel();
        vector<projectObject> fetchAllObjects();
        bool addProject(QString content);
        bool removeProject(projectObject project);
        vector<projectObject> objects;
};

#endif // PROJECTMODEL_H
