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
        cout << "Prec Tidak Ditemukan!" << endl;
    }else{
        k->next = prec->next;
        prec->next = k;
    }
}

void insertKeywordLast(ListKeyword &LK, adrKey k){
    adrKey n;
    n = LK.first;
    if (isEmpty(LK)){
        LK.first = k;
    } else {
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
        n = n->next;
    }
    return nullptr;
}

void deleteRelation(ListKeyword LK, adrR r){
    adrKey n;
    adrR m, prec;
    bool found;

    found = false;

    if (r == nullptr) {
        cout << "Error: Relasi tidak valid!" << endl;
        return;
    }

    n = LK.first;
    while(n != nullptr && !found){
        m = n->firstR;
        prec = nullptr;

        while(m != nullptr){
            if(m == r){
                found = true;

                if(prec == nullptr){
                    n->firstR = m->nextR;
                } else {
                    prec->nextR = m->nextR;
                }
                m->nextR = nullptr;
                delete m;

                cout << "Relasi berhasil dihapus!" << endl;
                return;
            }
            prec = m;
            m = m->nextR;
        }
        n = n->next;
    }
    if (!found){
        cout << "Error: Relasi tidak ditemukan!" << endl;
    }
}

void viewPaperbyKeyword(ListKeyword LK, infotypeKey k){
    adrKey n;
    adrR m;
    bool found = false;

    n = findElmKey(LK, k);

    if (n == nullptr) {
        cout << "ERROR: Keyword tidak ditemukan" << endl;
        return;
    }

    cout << "Paper dengan Keyword \"" << k << "\" yaitu: " << endl;
    cout << endl;

    m = n->firstR;
    while(m != nullptr){
        cout << "- " << m->infoRP->info.title << endl;
        found = true;
        m = m->nextR;
    }

    if (!found) {
        cout << "Tidak ada paper dengan keyword ini" << endl;
    }
}


void countRelationOfKeyword(ListKeyword LK){
    int hasil;
    adrR r;
    adrKey k;

    k = LK.first;

    if (k == nullptr) {
        cout << "List keyword kosong" << endl;
        return;
    }

    while(k != nullptr){
        hasil = 0;
        r = k->firstR;
        while(r != nullptr){
            hasil++;
            r = r->nextR;
        }
        cout << "Keyword: " << k->info << " memiliki relasi sebanyak: " << hasil << endl;
        k = k->next;
    }
}

void editRelation(ListKeyword LK, ListPaper LP, adrPaper p, adrKey newK, adrKey oldK){
    adrR m, newR;
    adrR prec;
    bool found;

    if(LK.first == nullptr){
        cout << "Error: List Keyword Kosong !" << endl;
        return;
    }

    if(LP.first == nullptr){
        cout << "Error: List Paper Kosong !" << endl;
        return;
    }

    if (p == nullptr || oldK == nullptr || newK == nullptr) {
        cout << "Error: Parameter tidak valid!" << endl;
        return;
    }

    m = oldK->firstR;
    prec = nullptr;
    found = false;

    while(m != nullptr){
        if(m->infoRP == p){
            found = true;
            break;
        }
        prec = m;
        m = m->nextR;
    }

    if (!found) {
        cout << "Error: Relasi tidak ditemukan!" << endl;
        return;
    }


    if (prec == nullptr) {
        oldK->firstR = m->nextR;
    } else {
        prec->nextR = m->nextR;
    }

    m->nextR = nullptr;
    if (newK->firstR == nullptr) {
        newK->firstR = m;
    } else {
        adrR temp = newK->firstR;
        while (temp->nextR != nullptr) {
            temp = temp->nextR;
        }
        temp->nextR = m;
    }

    cout << "Relasi Berhasil Diubah !" << endl;
}

void showAllPaperAndKeyword(ListKeyword LK, ListPaper LP){
    adrKey k;
    adrPaper p;
    adrR r;
    bool hasKeyword;

    p = LP.first;

    if (p == nullptr) {
        cout << "Tidak ada paper" << endl;
        return;
    }

    while(p != nullptr){
        cout << "\n========================================" << endl;
        cout << "Paper: " << p->info.title << endl;
        cout << "========================================" << endl;

        hasKeyword = false;
        k = LK.first;

        while(k != nullptr){
            r = k->firstR;
            while(r != nullptr){
                if(r->infoRP == p){
                    cout << "  Keyword: " << k->info << endl;
                    hasKeyword = true;
                }
                r = r->nextR;
            }
            k = k->next;
        }

        if (!hasKeyword) {
            cout << "  (Tidak ada keyword)" << endl;
        }

        p = p->next;
    }
}
