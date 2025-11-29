#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#include "string"
#include "Relation.h"

typedef struct Paper infotypePaper;
typedef struct elmPaper *adrPaper;
struct Paper{
    string title;
    string journal;
    string author;
    string date;
};

struct elmPaper{
    infotypePaper infoPaper;
    adrPaper nextPaper;
    elmR firstR;
};

struct ListPaper{
    adrPaper first;
};

createListPaper_1030323430027();
createElmPaper_();

insertPaperFirst_103032430027();
insertPaperAfter_103032430027();
insertPaperLast_103032430027();

deletePaperFirst_();
deletePaperAfter_();
deletePaperLast_();

findElmPaper_103032430027();
viewPaper_();

#endif // PAPER_H_INCLUDED
