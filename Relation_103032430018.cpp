#include "Keyword.h"
#include "Paper.h"
#include <iostream>
using namespace std;

void createElmR(adrKey k){
     k->firstR = nullptr;
}

void insertRelation(adrkey  k, adrPaper p){
    r = createElmR(k) // buat elm relationnya
    //menghubungkan paper ke keyword
    //baru insert

    if(p->firstR == nullptr){
        insertRFirst(adrPaper p, adrR relation){

        }
    }else{
        insertRLast(){

        }
    }
        //depan insertfirts, belakang last, dst. (all di paper child dan relation)
}

void insertRFirst(adrKey k, adrR r){
    if(k->firstR == nullptr){
        k->firstR = r
    }
}

void insertRAfter_103032430027(adrKey k, adrR r){
 //parameternya ada adrKey dan adrPaper (all insert)

}

void insertRLast(ListKeyword k, adrR r, adrPaper p){
    adrKey n;
    adrR x;

    n = k->first;
    while(n != nullptr){
        x = n->firstR;
        while(x->nextR != nullptr){
            x = x->nextR;
        }
        x->nextR = r;
        x->infoRP = p->infoPaper;
    }
}


