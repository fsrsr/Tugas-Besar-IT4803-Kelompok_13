#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "Paper.h"
#include "Keyword.h"

typedef struct elmR *adrR;

struct elmR{
    adrR nextR;
    adrPaper infoRC;
};

//103032430018
void insertRelation(adrKey k, adrPaper p);
void insertRFirst(adrPaper p, adrR relation);
void insertRAfter();
void insertRLast(adrPaper p, adrR relation);
void countRKeyword();

//103032430027
void deleteRFirst();
void deleteRAfter();
void deleteRLast();
void findElmR();
void viewR();
void countRPaper();

#endif // RELATION_H_INCLUDED



