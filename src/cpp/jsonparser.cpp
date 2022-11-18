#include "jsonparser.h"
#include "QFile"
#include <QJsonDocument>
#include <QJsonArray>
#include "QJsonObject"

JsonParser::JsonParser()
{

}

JsonParser::~JsonParser()
{

}

void JsonParser::save(QTableWidget * widget)
{
    QFile fileSpencer("TaskList.json");
    fileSpencer.open(QIODevice::ReadWrite);
    QJsonDocument jsonDoc;
    QJsonArray dataJson;

    for (int i=0;i<widget->rowCount() ;i++ ) {
        QJsonObject objectJson;
        objectJson.insert("Initials", widget->item(i,0)->text());
        objectJson.insert("Date", widget->item(i,1)->text());
        objectJson.insert("Description", widget->item(i,2)->text());
        dataJson.push_back(objectJson);
    }
    jsonDoc.setArray(dataJson);
    fileSpencer.write(QString(jsonDoc.toJson()).toStdString().c_str());
}

void JsonParser::read(QTableWidget * widget)
{
    QFile fileSpencer("TaskList.json");
    fileSpencer.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value;
    value = fileSpencer.readAll();
    fileSpencer.close();
    QJsonDocument doc = QJsonDocument::fromJson(value.toUtf8());
    QJsonArray json = doc.array();
    for (int i = 0;i<json.size() ;i++ ) {
       widget->insertRow(i);
       QJsonObject str = json [i].toObject();
       QString initials = str["Initials"].toString();
       QString date = str["Date"].toString();
       QString description = str["Description"].toString();
      widget->setItem(widget->rowCount()-1,0, new QTableWidgetItem(initials));
      widget->setItem(widget->rowCount()-1,1, new QTableWidgetItem(date));
      widget->setItem(widget->rowCount()-1,2, new QTableWidgetItem(description));
    }

}
