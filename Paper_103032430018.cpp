//DLL
#include "Paper.h"
#include <iostream>
using namespace std;

void createListPaper_1030323430027(ListPaper &P){
    P.first = nullptr;
    P.last = nullptr;
}

adrPaper createElmPaper_(infotypePaper x){
    adrPaper p;

    p = new elmPaper;
    p->firstR = nullptr;
    p->infoPaper =
    p->nextPaper =


}

bool isEmpty(ListPaper P);

/*
void insertKeywordFirst(ListKeyword &K, adrKey p){
    if(isEmpty(K)){
        K.first = p;
    }else{
        p->next = ListKeyword.first
        K.first = p;
    }
}

void insertKeywordAfter(ListKeyword &K, adrKey prec, adrKey p){
    if(prec == nullptr){
        cout << "Prec Tidak Ditemukan!"
    }else{
        p->next = prec->next;
        prect->next = p;
    }
}

void insertKeywordLast(ListKeyword &K, adrKey p){
    adrKey Q;
    Q = K.first
    if(isEmpty(K)){
        K.first = p;
    }else {
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = p;
    }
} */

