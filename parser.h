#ifndef PARSER_H
#define PARSER_H

#include "QTableWidget"


class Parser
{
public:
    Parser();
   virtual void save(QTableWidget*) = 0;
   virtual void read(QTableWidget*) = 0;
};

#endif // PARSER_H
