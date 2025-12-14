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

void deleteRelation(ListKeyword LK, adrR prec, adrR r){
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

void countRelationOfKeyword(ListKeyword LK){
    int hasil;
    adrR r;
    adrKey k;

    k = LK.first;
    while(k != nullptr){
        hasil = 0;
        r = k->firstR;
        while(r != nullptr){
            hasil++;
            r = r->nextR;
        }
        cout << "Keyword: " << k->info << "memiliki relasi sebanyak: " << hasil << endl;
    }
    k = k->next;
}

void editRelation(ListKeyword LK, ListPaper LP, adrPaper p, adrKey newK, adrKey oldK){
    adrPaper n;
    adrR m,z;
    adrKey k;

    if(LK.first == nullptr){
        cout << "Error: List Keyword Kosong !" << endl;
        return;
    } else {
        cout << "Error: List Paper Kosong !" << endl;
        return;
    }

    while(p != nullptr){
        k = LK.first;
        while(k != oldK){
            k = k->next;
        }
        if(k != oldK){
            cout << "Error: Keyword tersebut tidak ditemukan" << endl;
            return;
        }

        n = LP.first;
        while(n != p){
            n = n->next
        }
        if(n == p){
            m = k->firstR;
            while(m != nullptr){
                if(m->infoRP == p){
                    deleteRelation(LK, m, z);
                    while(k != newK){
                        k = k->next;
                    }
                    insertRelation(LK, m, n);
                    cout << "Relasi Berhasil Diubah !" << endl;
                    return;
                } else{
                    cout << "Tidak ada keyword yang berelasi dengan paper !"
                }
                m = m->nextR;
            }

        }else {
            cout << "Erorr: Paper tidak ditemukan pada List Paper!" << endl;
            return;
        }
    }
}

void showAllPaperAndKeyword(ListKeyword LK, ListPaper LP){
    adrKey k;
    adrPaper p;
    adrR r;

    k = LK.first;
    while(k != nullptr){
        p = LP.first;
        while(p != nullptr){
            cout << "Paper: " << p->info.title << endl;
            r = k->firstR;
            while(r != nullptr){
                if(r->infoRP == p){
                    cout << "Memiliki Keyword: " << k->info << endl;
                }
                r = r->nextR;
            }

        }
    }

}
