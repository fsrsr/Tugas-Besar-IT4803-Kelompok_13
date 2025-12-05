#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED
#include "string"
#include <iostream>
using namespace std;

typedef string infotypeKey;
typedef struct elmKeyword *adrKey;
typedef struct elmR *adrR;

struct elmR{
    adrR nextR;
    adrKey infoRC;
};

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
void adrKey findElmKey(ListKeyword B, infotypeKey x);
void deleteRFirst_();
void deleteRAfter_();
void deleteRLast_();
void viewR_();

//103032430018
void deleteKeywordFirst(ListKeyword &K, adrKey &p);
void deleteKeywordAfter(ListKeyword &K, adrKey prec, adrKey &p);
void deleteKeywordLast(ListKeyword &K, adrKey p);
void viewKey(ListKeyword K);
void insertRelation(adrkey  k, adrpaper p);
void insertRFirst(adrPaper p, adrR relation);
void insertRAfter();
void insertRLast(adrPaper p, adrR relation);
void findElmR();

#endif // KEYWORD_H_INCLUDED

// menu
// user masukin judul paper dan isinya
// nanya ke user, keyword satu satu

// kalo keyword udh ada yaudah, kalo blm create trus dimasukin ke list keyword
