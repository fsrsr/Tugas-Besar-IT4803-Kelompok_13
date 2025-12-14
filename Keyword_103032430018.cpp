#include "Keyword.h"
#include <iostream>
//SLL
using namespace std;

void createListKeyword(ListKeyword &K) {
    K.first = nullptr;
}

bool isEmpty(ListKeyword K) {
    return (K.first == nullptr);
}

adrKey createElmKeyword(infotypeKey x) {
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

void deleteKeywordLast(ListKeyword &K, adrKey p) {
    adrKey q;

    if (isEmpty(K)) {
        p = nullptr;
        cout << "List Kosong";
    } else if (K.first -> next = nullptr) {
        p = K.first;
        K.first = nullptr;
    } else {
        q = K.first;
        while (q -> next -> next != nullptr) {
            q = q -> next;
        }
        p = q -> next;
        q -> next = nullptr;
    }
}

void showKey(ListKeyword K) {
    adrKey p;

    p = K.first;
    while (p != nullptr) {
        cout << p->info;
        p = p -> next;
    }
}

adrR createElmR(adrPaper p){
    adrR n;
    n = createElmR();
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

void viewKeywordbyPaper(ListKeyword LK, adrKey k, adrPaper p); // point 13

int countRelationByKeyword(adrKey k){ // Membuat Count Relasi dari setiap element Keyword
    adrR m;
    int z;

    m = k->firstR;
    while(n != nullptr){
        if(m != nullptr){
            z++;
        }
        n = n->next;
    }
    return z;
}

int countRelationOfPaper(ListKeyword LK); // point 17

void showAllKeywordAndPaper(ListKeyword LK, adrKey k, adrPaper p){
    adrKey n;
    adrR m;
    n = LK.first;
    while(n != nullptr){
        m = n->firstR;
        cout << "Paper dengan Keyword " << n->info << ":" << endl;
        cout << endl;
        cout << "============ Paper =============" << endl;
        while(m != nullptr){
            cout << "Judul    :" << m->infoRP->info.title << endl;
            cout << "Jurnal   :" << m->infoRP->info.journal << endl;
            cout << "Terbit   :" << m->infoRP->info.date << endl;
            cout << "Kategori :" << m->infoRP->info.category << endl;
        }
        m = m->nextR;
    }
    n = n->next;
} // Membuat Show all data di List Paper beserta data Paper yang berelasi dengannya

void countNoRelationPaper(ListKeyword LK) // point 18
void findIsRelation()
