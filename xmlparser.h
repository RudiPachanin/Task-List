#ifndef XMLPARSER_H
#define XMLPARSER_H


#include "parser.h"



class XmlParser:public Parser
{
public:
    XmlParser();
    ~XmlParser();
    void save(QTableWidget*);
    void read(QTableWidget*);
};

#endif // XMLPARSER_H
