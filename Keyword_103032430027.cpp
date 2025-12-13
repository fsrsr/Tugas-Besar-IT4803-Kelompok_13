#include "Keyword.h"
#include "Paper.h"
#include <iostream>
using namespace std;
//SLL
void insertKeywordFirst(ListKeyword &LK, adrKey k){
    if(isEmpty(LK)){
        LK.first = k;
    }else{
        k->next = LK.first;
        LK.first = k;
    }
}

void insertKeywordAfter(ListKeyword &LK, adrKey prec, adrKey k){
    if(prec == nullptr){
        cout << "Prec Tidak Ditemukan!";
    }else{
        k->next = prec->next;
        prec->next = k;
    }
}

void insertKeywordLast(ListKeyword &LK, adrKey k){
    adrKey n;
    n = LK.first
    if(isEmpty(LK)){
        LK.first = k;
    }else {
        while(n->next != nullptr){
            n = n->next;
        }
        n->next = k;
    }
}

adrKey findElmKey(ListKeyword LK, infotypeKey x){
    adrKey n;
    n = LK.first;
    while(n != nullptr){
        if(n->info == x){
            return n;
        }
        n = n->next;
    }
    return nullptr;
}


adrR findElmR(ListKeyword LK, adrPaper p){
    adrKey n;
    adrR m;

    n = LK.first;
    while(n != nullptr){
        m = n->firstR;
        while(m != nullptr){
            if(m->infoRP == p){
                return m;
            }
            m = m->nextR;
        }
        n = n->next
    }
    return nullptr;
}

void deleteRFirst(ListKeyword LK, adrR r){ // belum fix
    adrKey n;
    adrR m;
    n = LK.first;
    while(n != nullptr){
        m = n->firstR;
        while(m != nullptr){
            if(m == n->firstR){
                n->firstR = nullptr;
            }else {
                r = m->nextR;
                m->nextR = r->nextR;
                r->nextR = nullptr;
            }
            m = m->nextR;
        }
        n = n->next
    }
}
void deleteRAfter(ListKeyword LK, adrR prec, adrR r){
    adrKey n;
    adrR m;
    n = LK.first;
    while(n!=nullptr){
        prec = findElmR(LK, p);
        m = n->firstR;
        while(m != nullptr){
            if(prec == n->firstR){
                n->firstR = nullptr;)
            }else{
                while(m->nextR != prec){
                    m = m->nextR;
                }
                r = prec->nextR;
                prec->nextR = r->nextR;
                r->nextR = nullptr;
            }
        }
    }
}
void deleteRLast(ListKeyword LK, adrR r){
    adrKey n;
    adrR m;
    n = LK.first;
    while(n!=nullptr){
        m = n->firstR;
        while(m->nextR->nextR != nullptr){
                m = m->nextR;
            }
            r = m->nextR;
            m->nextR = nullptr;
        }
    }
}

void viewPaperbyKeyword(ListKeyword LK, infotypeKey k){// Membuat Show data Paper yang berelasi dengan Keyword tertentu
    adrKey n;
    adrR m;
    adrPaper p;

    n = LK.first
    while(n!=nullptr){
        m = n->firstR;
        while(m!= nullptr){
            cout << m->infoRP->info.journal << ", " << m->infoRP->info.author << ", "<< m->infoRP->info.date << ", " << m->infoRP->info.category << endl;
            }
            m = m->next;
        }
        n = n->next;
    }
}

int countRelationOfPaper(adrKey k){ //Membuat Count Relasi yang dimiliki oleh Paper tertentu
    int n;
    adrR x;

    x = k->firstR;
    while(x != nullptr){
        n++;
        x = x->next;
    }
   return n;
}

void editRelation(ListKeyword LK, ListPaper LP, adrPaper p, adrKey newK, adrKey oldK){

    if(LK.first == nullptr){
        cout << "Error List Keyword Kosong !" << endl;
    }




} // Membuat Edit Relasi / mengganti Paper dari Keyword tertentu
