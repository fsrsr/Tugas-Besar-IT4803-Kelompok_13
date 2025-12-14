#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

typedef struct Paper infotypePaper;
typedef struct elmPaper *adrPaper;

struct Paper{
    string title;
    string journal;
    string author;
    string date;
    string category;
};

struct elmPaper{
    infotypePaper info;
    adrPaper next;
    adrPaper prev;
};

struct ListPaper{
    adrPaper first;
    adrPaper last;
};

//103032430027 point 5 & 11
void deletePaperFirst(ListPaper &LP, adrPaper &p);
void deletePaperAfter(ListPaper &LP, adrPaper prec, adrPaper &p);
void deletePaperLast(ListPaper &LP, adrPaper &p);
void showPaper(ListPaper LP);

//103032430018 point 2 & 8
void createListPaper(ListPaper &LP);
adrPaper createElmPaper(infotypePaper x);
bool isEmptyPaper(ListPaper LP);
void insertPaperFirst(ListPaper &LP, adrPaper p);
void insertPaperAfter(ListPaper &LP, adrPaper prec, adrPaper p);
void insertPaperLast(ListPaper &LP, adrPaper p);
adrPaper findElmPaper(ListPaper LP, infotypePaper x);


#endif // PAPER_H_INCLUDED
