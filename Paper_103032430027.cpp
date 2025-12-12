#include "Paper.h"
#include <iostream>
using namespace std;

//DLL

void createListPaper(ListPaper &LP){
    LP.first = nullptr;
    LP.last = nullptr;
}

bool isEmpty(ListPaper LP);
    if(LP == nullptr){
        return true;
    }
    return false;
}

adrPaper createElmPaper(infotypePaper x){
    adrPaper p;

    p = new elmPaper;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
}

void deletePaperFirst(ListPaper &LP, adrPaper &p){
    if (isEmptyPaper(LP)){
        p = nullptr;
        cout << "List kosong";
    } else if (LP.first == LP.last){
        p = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    } else{
        p = P.first;
        LP.first = p->next;
        p->next = nullptr;
        LP.first -> prev = nullptr;
    }
}

void deletePaperAfter(ListPaper &LP, adrPaper prec, adrPaper &p){
    if (isEmptyPaper(LP)){
        p = nullptr;
        cout << "List kosong";
    } else if (LP.first == LP.last){
        p = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    } else{
        p = prec->next;
        prec->next = p->next;
        p->next->prev = prec;
        p->next = nullptr;
        p->prev = nullptr;
    }
}

void deletePaperLast(ListPaper &LP, adrPaper &p){
    if (isEmptyPaper(LP)){
        p = nullptr;
        cout << "List kosong";
    } else if (LP.first == LP.last){
        p = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    } else {
        p = LP.last;
        LP.last = p->prev;
        p->prev = nullptr;
        LP.last -> next = nullptr;
    }
}

void findElmPaper(ListPaper LP, infotypePaper x){
    adrPaper n;
    n = LP.first;

    while(n != nullptr){
        if(n->info.title == x.title || n->info.journal == x.journal || n->info.author == x.author || n->info.date == x.date || n->info.category == x.category){
            return n;
        }
        n = n->next;
    }
    return nullptr;
}

