//DLL
#include "Paper.h"
#include <iostream>
using namespace std;

void deletePaperFirst(ListPaper &P, adrPaper &q) {
    if (isEmptyPaper(P)) {
        q = nullptr;
        cout << "List kosong";
    } else if (P.first == P.last) {
        q = P.first;
        P.first = nullptr;
        P.last = nullptr;
    } else {
        q = P.first;
        P.first = q -> next;
        q -> next = nullptr;
        P.first -> prev = nullptr;
    }
}

void deletePaperAfter(ListPaper &P, adrPaper prec, adrPaper &q) {
    if (isEmptyPaper(P)) {
        q = nullptr;
        cout << "List kosong";
    } else if (P.first == P.last) {
        q = P.first;
        P.first = nullptr;
        P.last = nullptr;
    } else {
        q = prec -> next;
        prec -> next = q -> next;
        q -> next -> prev = prec;
        q -> next = nullptr;
        q -> prev = nullptr;
    }
}

void deletePaperLast(ListPaper &P, adrPaper &q) {
    if (isEmptyPaper(P)) {
        q = nullptr;
        cout << "List kosong";
    } else if (P.first == P.last) {
        q = P.first;
        P.first = nullptr;
        P.last = nullptr;
    } else {
        q = P.last;
        P.last = q -> prev;
        q -> prev = nullptr;
        P.last -> next = nullptr;
    }
}

void showPaper(ListPaper P) {
    adrPaper q;

    q = P.first;
    while (q != nullptr) {
        cout << q -> infoPaper
        q -> next;
    }
}


