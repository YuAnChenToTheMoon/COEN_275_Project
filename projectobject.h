#ifndef PROJECTOBJECT_H
#define PROJECTOBJECT_H

#include <QString>
#include <QDateTime>

class projectObject
{
    public:
        projectObject();
        int projectID;
        QString name;
        QString status;
        QDateTime createDate;
        QDateTime updateDate;
        bool updateProject(QString status);
};

#endif // PROJECTOBJECT_H
