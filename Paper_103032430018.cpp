//DLL
#include "Paper.h"
#include <iostream>

using namespace std;

void insertPaperFirst(ListPaper &LP, adrPaper p){
    if (isEmptyPaper(LP)){
        LP.first = p;
        LP.last = p;
    } else{
        p->next = LP.first;
        LP.first->prev = p;
        LP.first = p;
    }
}

void insertPaperAfter(ListPaper &LP, adrPaper prec, adrPaper p){
    if (isEmptyPaper(LP)){
        LP.first = p;
        LP.last = p;
    } else{
        p->prev = prec;
        p->next = prec->next;
        prec->next->prev = p;
        prec->next = p;
    }
}

void insertPaperLast(ListPaper &LP, adrPaper p){
    if (isEmptyPaper(LP)){
        LP.first = p;
        LP.last = p;
    } else{
        LP.last->next = p;
        p->prev = LP.last;
        LP.last = p;
    }
}

void showPaper(ListPaper LP){
    adrPaper p;

    p = LP.first;
    while (p != nullptr){
        cout << p->info.title << ", " << p ->info.author << ", " << p ->info.year << ", " << p ->info.category << endl;
        p->next;
    }
}
