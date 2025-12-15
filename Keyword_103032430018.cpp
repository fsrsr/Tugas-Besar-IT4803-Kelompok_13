//SLL
#include "Keyword.h"
#include <iostream>
#include "Paper.h"

using namespace std;

void createListKeyword(ListKeyword &LK) {
    LK.first = nullptr;
}

bool isEmpty(ListKeyword LK) {
    return (LK.first == nullptr);
}

adrKey createElmKeyword(infotypeKey x) {
    adrKey p;

    p = new elmKeyword;
    p -> info = x;
    p -> next = nullptr;
    return p;
}

void deleteKeywordFirst(ListKeyword &LK, adrKey &k) {
    if (isEmpty(LK)) {
        cout << "List Kosong";
    } else if (LK.first -> next == nullptr) {
        k = LK.first;
        LK.first = nullptr;
    } else {
        k = LK.first;
        LK.first = k -> next;
        k -> next = nullptr;
    }
}

void deleteKeywordAfter(ListKeyword &LK, adrKey prec, adrKey &k) {
    if (isEmpty(LK)) {
        cout << "List Kosong";
    } else if (LK.first -> next = nullptr) {
        k = LK.first;
        LK.first = nullptr;
    } else {
        k = prec -> next;
        prec -> next = k -> next;
        k -> next = nullptr;
    }
}

void deleteKeywordLast(ListKeyword &LK, adrKey &k) {
    adrKey q;

    if (isEmpty(LK)) {
        k = nullptr;
        cout << "List Kosong";
    } else if (LK.first -> next = nullptr) {
        k = LK.first;
        LK.first = nullptr;
    } else {
        q = LK.first;
        while (q -> next -> next != nullptr) {
            q = q -> next;
        }
        k = q -> next;
        q -> next = nullptr;
    }
}

void showKey(ListKeyword LK) {
    adrKey p;

    p = LK.first;
    while (p != nullptr) {
        cout << p->info;
        p = p -> next;
    }
}

adrR createElmR(adrPaper p){
    adrR n;
    n = new elmR;
    n->nextR = nullptr;
    n->infoRP = p;
    return n;
}

void insertRelation(ListKeyword LK, adrR r, adrPaper p){
    adrKey n;
    adrR m;
    n = LK.first;
    while(n != nullptr){
        m = n->firstR;
        while(m != nullptr){
            while(m->nextR != nullptr){
                m = m->nextR;
            }
            m->nextR = r;
            m->infoRP = p;
        }
        m = m->nextR;
    }
    n = n->next;
}

void viewKeywordbyPaper(ListKeyword LK,ListPaper LP, infotypePaper p){  // point 13

    adrKey n;
    adrR m;
    adrPaper z;

    n = LK.first;
    z = LP.first;
    while(n!=nullptr){
        m = n->firstR;
        cout << "Paper dengan judul " << p.title << " memiliki keyword: " << endl;
        cout << endl;
        while(m!= nullptr){
            if(z->info.title == p.title){
                cout << n->info << endl;
            }
            m = m->nextR;
        }
        n = n->next;
    }
    cout << "ERROR: Keyword Tidak Ditemukan" << endl;
}

int countRelationByKeyword(adrKey k){ // Membuat Count Relasi dari setiap element Keyword
    adrR m;
    int z;

    z = 0;
    m = k->firstR;
    while(k != nullptr){
        if(m != nullptr){
            z++;
        }
        k = k->next;
    }
    return z;
}

int countRelationOfPaper(ListKeyword LK, ListPaper LP, infotypePaper x){ // point 17
    adrKey k;
    adrPaper p;
    adrR r;
    bool f;
    int banyak;

    k = LK.first;
    banyak = 0;
    p = findElmPaper(LP, x);
    while (k != nullptr) {
        r = k ->firstR;
        while (r != nullptr) {
            if (r ->infoRP == p) {
                banyak++;
            }
            r = r ->nextR;
        }
        k = k ->next;
    }
    cout << "ERROR: Paper Tidak Ditemukan !" << endl;
}

void showAllKeywordAndPaper(ListKeyword LK, ListPaper LP){
    adrKey n;
    adrR m;
    n = LK.first;
    while (n != nullptr) {
        cout << "Paper dengan Keyword " << n -> info << ": " << endl;
        m = n -> firstR;
        while (m != nullptr) {
            cout << "  Judul: " << m -> infoRP -> info.title << endl;
            cout << "  Tahun: " << m ->infoRP->info.year << endl;
            cout << "  Penulis: " << m ->infoRP->info.author << endl;
            cout << "  Kategori: " << m ->infoRP->info.category << endl;

            m = m->nextR;
        }
        n = n->next;
    }
} // Membuat Show all data di List Paper beserta data Paper yang berelasi dengannya

void countNoRelationPaper(ListKeyword LK, ListPaper LP){ // point 18
    adrKey k;
    adrPaper p;
    adrR r;
    int banyak, tanpaRel;

    k = LK.first;
    p = LP.first;
    while (k != nullptr) {
        r = k ->firstR;
        while (r != nullptr) {
            if (r ->infoRP == p) {
                banyak++;
            }
        }

        if (banyak == 0) {
            tanpaRel++;
        }
    }
}
