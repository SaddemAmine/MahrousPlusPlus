#include "systeme.h"
#include <QDebug>
systeme::systeme()
{

}
QString systeme::login(QString cin,QString pwd)
{

        QSqlQuery query;
        query.prepare("select idfonction from personnels where cin = :cin and password = :pwd ; ");
        query.bindValue(":cin",cin);
        query.bindValue(":pwd",pwd);
        if(query.exec()){
            while(query.next()){
                return query.value(0).toString();
            }
        }
        return "";
    }
