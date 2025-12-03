#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED
#include "string"
#include <iostream>
using namespace std;

typedef string infotypeKey;
typedef struct elmKeyword *adrKey;

struct elmKeyword{
    infotypeKey info;
    adrKey next;
};

struct ListKeyword{
    adrKey first;
};

void createListKeyword(ListKeyword &K);
adrKey allocateKeyword(infotypeKey x);
bool isEmpty(ListKeyword K);

void insertKeywordFirst(ListKeyword &K, adrKey p);
void insertKeywordAfter(ListKeyword &K, adrKey prec, adrKey p);
void insertKeywordLast(ListKeyword &K, adrKey p);

void deleteKeywordFirst(ListKeyword &K, adrKey &p);
void deleteKeywordAfter(ListKeyword &K, adrKey prec, adrKey &p);
void deleteKeywordLast(ListKeyword &K, adrKey p);

adrKey findElmKey(ListKeyword B, infotypeKey x);
void viewKey(ListKeyword K);

#endif // KEYWORD_H_INCLUDED
