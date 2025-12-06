#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED
#include <string>
#include "Relation.h"
#include <iostream>
using namespace std;

typedef string infotypeKey;
typedef struct elmKeyword *adrKey;

struct elmKeyword{
    infotypeKey info;
    adrKey next;
    elmR firstR;
};

struct ListKeyword{
    adrKey first;
};

void createListKeyword(ListKeyword &K);
adrKey allocateKeyword(infotypeKey x);
bool isEmpty(ListKeyword K);

// 103032430027
void insertKeywordFirst(ListKeyword &K, adrKey p);
void insertKeywordAfter(ListKeyword &K, adrKey prec, adrKey p);
void insertKeywordLast(ListKeyword &K, adrKey p);
void findElmKey(ListKeyword B, infotypeKey x);

//103032430018
void deleteKeywordFirst(ListKeyword &K, adrKey &p);
void deleteKeywordAfter(ListKeyword &K, adrKey prec, adrKey &p);
void deleteKeywordLast(ListKeyword &K, adrKey &p);
void showKey(ListKeyword K);

#endif // KEYWORD_H_INCLUDED

// menu
// user masukin judul paper dan isinya
// nanya ke user, keyword satu satu

// kalo keyword udh ada yaudah, kalo blm create trus dimasukin ke list keyword
