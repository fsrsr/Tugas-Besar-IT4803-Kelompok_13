#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED
#include "Paper.h"
#include <string>
#include <iostream>
#include "Paper.h"
using namespace std;

typedef string infotypeKey;
typedef struct elmKeyword *adrKey;
typedef struct elmR *adrR;

struct elmR{
    adrR nextR;
    adrPaper infoRP; // RP : relasi paper
};

struct elmKeyword{
    infotypeKey info;
    adrKey next;
    adrR firstR;
};

struct ListKeyword{
    adrKey first;
};

//create Parent
void createListKeyword(ListKeyword &LK);
adrKey createElmKeyword(infotypeKey x);
bool isEmpty(ListKeyword LK);

//create relasi
adrKey createElmR(elmKeyword info);


// 103032430027 (Parent)
void insertKeywordFirst(ListKeyword &LK, adrKey k);
void insertKeywordAfter(ListKeyword &LK, adrKey prec, adrKey k);
void insertKeywordLast(ListKeyword &LK, adrKey k);
adrKey findElmKey(ListKeyword LK, infotypeKey x);

//103032430018 (Parent)
void deleteKeywordFirst(ListKeyword &LK, adrKey &k);
void deleteKeywordAfter(ListKeyword &LK, adrKey prec, adrKey &k);
void deleteKeywordLast(ListKeyword &LK, adrKey &k);
void showKey(ListKeyword LK);

//103032430027 (Relasi)
void deleteRFirst(ListKeyword LK, adrR r, adrPaper p);
void deleteRAfter(ListKeyword LK, adrR r, adrPaper p);
void deleteRLast(ListKeyword LK, adrR r, adrPaper p);
void viewPaperbyKeyword(ListKeyword LK, infotypeKey k); // Membuat Show data Paper yang berelasi dengan Keyword tertentu
int countRelationOfPaper(ListKeyword LK, infotypePaper info, ListPaper LP); //Membuat Count Relasi yang dimiliki oleh Paper tertentu
void editRelation(ListKeyword LK, ListPaper LP, adrPaper p, adrKey k, adrKey oldK); // Membuat Edit Relasi / mengganti Paper dari Keyword tertentu
adrR findElmR(ListKeyword LK, adrPaper p);

//103032430018 (Relasi)
void insertRFirst(ListKeyword LK, adrR r, adrPaper p);
void insertRAfter(ListKeyword LK, adrR r, adrPaper p);
void insertRLast(ListKeyword LK, adrR r, adrPaper p);
void viewKeywordAndPaper(); // Membuat Show data Keyword beserta data Paper yang masing-masing Paper miliki
int countRelationByKeyword(); // Membuat Count Relasi dari setiap element Keyword
int countPaperNoRelation(); // Membuat Count element Paper yang tidak memiliki Relasi
void showAllKeywordAndPaper(); // Membuat Show all data di List Paper beserta data Paper yang berelasi dengannya

#endif // KEYWORD_H_INCLUDED

