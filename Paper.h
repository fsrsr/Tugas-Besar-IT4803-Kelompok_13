#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#include <string>
#include "Relation.h"
#include <iostream>
using namespace std;

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
    adrPaper prevPaper;
     //isinya null
};

struct ListPaper{
    adrPaper first;
    adrPaper last;
};

//103032430027
void deletePaperFirst(ListPaper &P, adrPaper &q);
void deletePaperAfter(ListPaper &P, adrPaper prec, adrPaper &q);
void deletePaperLast(ListPaper &P, adrPaper &q);
void showPaper(ListPaper P);
void showrPaperR();

//103032430018
void createListPaper(ListPaper &P);
adrPaper createElmPaper(infotypePaper x);
bool isEmptyPaper(ListPaper P);
void insertPaperFirst(ListPaper &P, adrPaper q);
void insertPaperAfter(ListPaper &P, adrPaper prec, adrPaper q);
void insertPaperLast(ListPaper &P, adrPaper q);
void findElmPaper(ListPaper P, infotypePaper x);
void countPaperNotR();


//searchPaperWithKeyword(ListPaper LP, adrKey k){
    //adrPaper p = LP->first;
    //while p != nullptr{
       // adrR r = p->firstR;
        //while (r != nullptr || notFound){
            //if (r->infoRC == k){
                //cout << p->info.judul;
                //notFound = true;
            //}
            //r = r->nextR;
        //}
        //p = p->next
    //}
//}

#endif // PAPER_H_INCLUDED
