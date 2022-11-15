#include "xmlparser.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include "QDomDocument"
#include "QXmlStreamReader"


XmlParser::XmlParser()
{

}

void XmlParser::createNewXml(QTableWidget* widget)
{
    QFile fileSpencer ("TaskList.xml");
    fileSpencer.open(QIODevice::ReadWrite);

    QDomDocument doc;
    QDomElement root = doc.createElement("Tasks");
    doc.appendChild(root);

    for (int row = 0;row < widget->rowCount() ;row++ ) {
        QDomElement task = doc.createElement("Task");
        QDomElement fio = doc.createElement("Initials");
        QDomElement date = doc.createElement("Date");
        QDomElement description = doc.createElement("Description");

        fio.appendChild(doc.createTextNode(widget->item(row,0)->text()));
        date.appendChild(doc.createTextNode(widget->item(row,1)->text()));
        description.appendChild(doc.createTextNode(widget->item(row,2)->text()));
        task.appendChild(fio);
        task.appendChild(date);
        task.appendChild(description);

        root.appendChild(task);
    }
    QTextStream out(&fileSpencer);
    doc.save(out, 4);
    fileSpencer.close();
}

void XmlParser::readXml(QTableWidget* widget)
{
    QFile fileSpencer ("TaskList.xml");
    fileSpencer.open(QIODevice::ReadWrite);

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&fileSpencer);
    xmlReader.readNext();

    while(!xmlReader.atEnd()){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="Task"){
                widget->insertRow(widget->rowCount());
            }
            if(xmlReader.name() == "Initials"){
                QString findElement;
                findElement = xmlReader.readElementText();
                widget->setItem(widget->rowCount()-1,0, new QTableWidgetItem(findElement));
            }
            if(xmlReader.name()=="Date"){
                QString findElement;
                findElement = xmlReader.readElementText();
                widget->setItem(widget->rowCount()-1,1, new QTableWidgetItem(findElement));
            }
            if(xmlReader.name()=="Description"){
                QString findElement;
                findElement = xmlReader.readElementText();
                widget->setItem(widget->rowCount()-1,2, new QTableWidgetItem(findElement));
            }

        }
        xmlReader.readNext();
    }

}
