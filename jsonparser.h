#ifndef JSONPARSER_H
#define JSONPARSER_H


#include "parser.h"

class JsonParser:public Parser
{
public:
    JsonParser();
    ~JsonParser();

    // Parser interface
public:
    void save(QTableWidget *);
    void read(QTableWidget *);
};

#endif // JSONPARSER_H
