#ifndef BUGOBJECT_H
#define BUGOBJECT_H

#include <QString>
#include <QDateTime>

class bugObject
{
    public:
        bugObject();
        int bugID;
        QString name;
        QString status;
        QString comment;
        QDateTime createDate;
        QDateTime updateDate;
};

#endif // BUGOBJECT_H
