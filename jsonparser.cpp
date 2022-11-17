#include "jsonparser.h"
#include "QFile"
#include <QJsonDocument>
#include <QJsonArray>
#include "QJsonObject"

JsonParser::JsonParser()
{

}

void JsonParser::save(QTableWidget * widget)
{
    QFile loadFile("TaskList.json");
    loadFile.open(QIODevice::ReadWrite);
    QJsonObject objectJson;
    QJsonDocument jsonDoc;
    QJsonArray dataJson;
    objectJson.insert("Initials", widget->item(0,0)->text());
    objectJson.insert("Date", widget->item(0,1)->text());
    objectJson.insert("Description", widget->item(0,2)->text());
    dataJson.push_back(objectJson);
    jsonDoc.setObject(objectJson);
}

void JsonParser::read(QTableWidget * widget)
{


}
