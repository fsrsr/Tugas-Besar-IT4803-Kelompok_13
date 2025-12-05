#include "Keyword.h"
#include <iostream>
using namespace std;
//SLL
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
}
