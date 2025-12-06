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

void deleteKeywordLast(ListKeyword &K, adrKey p) {
    adrkey q;

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
        cout << p -> infotypeKey;
        p = p -> next;
    }
}
