#include "Keyword.h"
#include <iostream>
#include "Paper.h"
#include <string>
#include "main.h"
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
    p->info = x;
    p->next = nullptr;
    p->firstR = nullptr;
    return p;
}

void deleteKeywordFirst(ListKeyword &LK, adrKey &p) {
    if (isEmpty(LK)) {
        p = nullptr;
        cout << "List Kosong" << endl;
    } else if (LK.first->next == nullptr) {
        p = LK.first;
        LK.first = nullptr;
    } else {
        p = LK.first;
        LK.first = LK.first->next;
        p->next = nullptr;
    }
}

void deleteKeywordAfter(ListKeyword &LK, adrKey prec, adrKey &p) {
    if (isEmpty(LK)) {
        p = nullptr;
        cout << "List Kosong" << endl;
    } else if (prec == nullptr || prec->next == nullptr) {
        p = nullptr;
        cout << "Tidak ada elemen setelah prec" << endl;
    } else {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteKeywordLast(ListKeyword &LK, adrKey &k) {
    adrKey p;

    if (isEmpty(LK)) {
        k = nullptr;
        cout << "List Kosong" << endl;
    } else if (LK.first->next == nullptr) {
        k = LK.first;
        LK.first = nullptr;
    } else {
        p = LK.first;
        while (p->next->next != nullptr) {
            p = p->next;
        }
        k = p->next;
        p->next = nullptr;
    }
}

void showKey(ListKeyword LK) {
    adrKey p;

    p = LK.first;
    if (p == nullptr) {
        cout << "List keyword kosong" << endl;
    } else {
        while (p != nullptr) {
            cout << p->info << endl;
            p = p->next;
        }
    }
}

adrR createElmR(adrPaper p){
    adrR n;
    n = new elmR;
    n->nextR = nullptr;
    n->infoRP = p;
    return n;
}

void insertRelation(adrKey k, adrR r){
    adrR last;

    if (k == nullptr || r == nullptr){
        return;
    }

    if (k->firstR == nullptr) {
        k->firstR = r;
    } else {
        last = k->firstR;
        while (last->nextR != nullptr) {
            last = last->nextR;
        }
        last->nextR = r;
    }
}

void connect(adrKey k, adrPaper p){
    adrR r, newRel;

    if (k == nullptr || p == nullptr) {
        cout << "Error: Keyword atau paper tidak valid!" << endl;
        return;
    }

    r = k->firstR;
    while (r != nullptr) {
        if (r->infoRP == p) {
            cout << "Paper sudah terhubung dengan keyword ini!" << endl;
            return;
        }
        r = r->nextR;
    }

    newRel = createElmR(p);
    insertRelation(k, newRel);
    cout << "Paper " << "'" << p->info.title << "'" << " berhasil dihubungkan dengan keyword " << k->info << " !"<< endl;
}

void viewKeywordbyPaper(ListKeyword LK, ListPaper LP, string p){
    adrKey n;
    adrR m;
    bool found = false;

    n = LK.first;
    while(n != nullptr){
        m = n->firstR;
        while(m != nullptr){
            if(m->infoRP != nullptr && m->infoRP->info.title == p){
                cout << "- " << n->info << endl;
                found = true;
                break;
            }
            m = m->nextR;
        }
        n = n->next;
    }

    if (!found) {
        cout << "Tidak ada keyword untuk paper tersebut" << endl;
    }
}

int countRelationByKeyword(adrKey k){
    adrR m;
    int z;

    if (k == nullptr){
        return 0;
    }
    z = 0;
    m = k->firstR;
    while(m != nullptr){
        z++;
        m = m->nextR;
    }
    return z;
}

int countRelationOfPaper(ListKeyword LK, ListPaper LP){
    adrKey k;
    adrPaper p;
    adrR r;
    int banyak;
    string x;

    cout << "Masukkan judul paper: ";
    cin.ignore();
    getline(cin, x);

    k = LK.first;
    banyak = 0;
    p = findElmPaper(LP, x);

    if (p == nullptr) {
        cout << "Paper tidak ditemukan" << endl;
        return 0;
    }

    while (k != nullptr) {
        r = k->firstR;
        while (r != nullptr) {
            if (r->infoRP == p) {
                banyak++;
            }
            r = r->nextR;
        }
        k = k->next;
    }
    return banyak;
}

void showAllKeywordAndPaper(ListKeyword LK, ListPaper LP){
    adrKey n;
    adrR m;
    n = LK.first;

    if (n == nullptr) {
        cout << "Tidak ada keyword" << endl;
        return;
    }

    while (n != nullptr) {
        cout << "\n========================================" << endl;
        cout << "Keyword: " << n->info << endl;
        cout << "========================================" << endl;
        m = n->firstR;

        if (m == nullptr) {
            cout << "  (Tidak ada paper)" << endl;
        }

        while (m != nullptr) {
            cout << "  Judul: " << m->infoRP->info.title << endl;
            cout << "  Tahun: " << m->infoRP->info.year << endl;
            cout << "  Penulis: " << m->infoRP->info.author << endl;
            cout << "  Kategori: " << m->infoRP->info.category << endl;
            cout << "  ---" << endl;

            m = m->nextR;
        }
        n = n->next;
    }
}

int countNoRelationPaper(ListKeyword LK, ListPaper LP){
    adrKey k;
    adrPaper p;
    adrR r;
    int tanpaRel = 0;
    bool hasRelation;

    p = LP.first;
    while (p != nullptr) {
        hasRelation = false;
        k = LK.first;

        while (k != nullptr) {
            r = k->firstR;
            while (r != nullptr) {
                if (r->infoRP == p) {
                    hasRelation = true;
                    break;
                }
                r = r->nextR;
            }
            if (hasRelation) break;
            k = k->next;
        }

        if (!hasRelation) {
            tanpaRel++;
        }
        p = p->next;
    }

    return tanpaRel;
}
