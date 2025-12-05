#include "Paper.h"
#include <iostream>
using namespace std;

//DLL

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

void deletePaperFirst_();
void deletePaperAfter_();
void deletePaperLast_();

void createListKeyword(ListKeyword &K) {
    K.first = nullptr;
}

bool isEmpty(ListKeyword K) {
    return (K.first == nullptr);
}

adrKey allocateKeyword(infotypeKey x) {
    adrKey p;

    p = new elmKeyword;
    p -> info = x;
    p -> next = nullptr;
}

void deleteKeywordFirst(ListKeyword &K, adrKey &p) {
    if (isEmpty(K)) {
        p = nullptr;
        cout << "List Kosong";
    } else if (K.first -> next == nullptr) {
        p = K.first;
        K.first = nullptr;
    } else {
        p = K.first;
        K.first = K.first -> next;
        p -> next = nullptr;
    }
}

void deleteKeywordAfter(ListKeyword &K, adrKey prec, adrKey &p) {
    if (isEmpty(K)) {
        p = nullptr;
        cout << "List Kosong";
    } else if (K.first -> next = nullptr) {
        p = K.first;
        K.first = nullptr;
    } else {
        p = prec -> next;
        prec -> next = p -> next;
        p -> next = nullptr;
    }
}
void deleteKeywordLast(ListKeyword &K, adrKey p){




}
