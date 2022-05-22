#include "projectmodel.h"

projectModel::projectModel(){}

vector<projectObject> projectModel::fetchAllObjects()
{
    objects = vector<projectObject>();
    QString qry_s = "SELECT * FROM project_management.project";
    QSqlQuery qry =  DB::getInstance()->read(qry_s);
    while(qry.next())
    {
        projectObject newObject = projectObject();
//        int rowNum = qry.at();
//        int columnNum = qry.record().count();
        newObject.projectID = qry.value(0).toInt();
        int nameFieldNo = qry.record().indexOf("name");
        newObject.name = qry.value(nameFieldNo).toString();
        int statusNo = qry.record().indexOf("status");
        newObject.status = qry.value(statusNo).toString();
        int createDateNo = qry.record().indexOf("create_date");
        newObject.createDate = qry.value(createDateNo).toDateTime();
        int updateDateNo = qry.record().indexOf("update_date");
        newObject.updateDate = qry.value(updateDateNo).toDateTime();
        objects.push_back(newObject);
    }
    return objects;
}

bool projectModel::addProject(QString content)
{
     QString qry_s =  QString("INSERT INTO `project_management`.`project` (`name`, `status`) VALUES ('%1', '%2');").arg(content, "New");
     return DB::getInstance()->write(qry_s);
}

bool projectModel::removeProject(projectObject project)
{
    QString qry_s =  QString("DELETE FROM `project_management`.`project` WHERE (`id` = %1);").arg(project.projectID);
    return DB::getInstance()->write(qry_s);
}

