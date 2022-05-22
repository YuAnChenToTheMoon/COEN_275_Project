#include "taskobject.h"
#include "db.h"

taskObject::taskObject(){}

bool taskObject::updateTask(QString new_status, QString new_comment)
{
    QString qry_s = QString("UPDATE project_management.task SET project_management.task.status = '%1', project_management.task.comment = '%2', project_management.task.update_date = NOW() WHERE project_management.task.id = %3;").arg(new_status, new_comment, QString::number(taskID));
    return DB::getInstance()->write(qry_s);
}

bool taskObject::assignTask(user usr)
{
    QString qry_s = QString("UPDATE project_management.task SET project_management.task.position_id = %1 WHERE project_management.task.id = %2;").arg(QString::number(usr.posID), QString::number(taskID));
    return DB::getInstance()->write(qry_s);
}
