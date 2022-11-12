#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "QTableWidget"



class XmlParser
{
public:
    XmlParser();
    void createNewXml(QTableWidget*);
    void readXml();
};

#endif // XMLPARSER_H
