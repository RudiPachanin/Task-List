#include "xmlparser.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include "QDomDocument"

XmlParser::XmlParser()
{

}

void XmlParser::createNewXml(QTableWidget* widget)
{
    QFile fileSpencer ("TaskList.xml");
    fileSpencer.open(QIODevice::ReadWrite | QIODevice::Truncate);


    QDomDocument doc;
    QDomElement root = doc.createElement("Tasks");
    doc.appendChild(root);

    for (int row =0;row < widget->rowCount() ;row++ ) {

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
