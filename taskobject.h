#ifndef TASKOBJECT_H
#define TASKOBJECT_H

#include "projectobject.h"
#include "user.h"
#include <QString>

class taskObject: public projectObject
{
    public:
        taskObject();
        int taskID;
        QString name;
        QString status;
        QString owner;
        QDateTime createDate;
        QDateTime updateDate;
        bool updateTask(QString status, QString comment);
        bool assignTask(user usr);
};

#endif // TASKOBJECT_H
