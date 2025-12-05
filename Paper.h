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
     //isinya null
};

struct ListPaper{
    adrPaper first;
    adrPaper last;
};

void createListPaper_1030323430027(ListPaper &P);
adrPaper createElmPaper_(infotypePaper x);
bool isEmpty(ListPaper P);

void insertPaperFirst_103032430027();
void insertPaperAfter_103032430027();
void insertPaperLast_103032430027();

void deletePaperFirst_();
void deletePaperAfter_();
void deletePaperLast_();

void findElmPaper_103032430027();
void viewPaper_();

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
