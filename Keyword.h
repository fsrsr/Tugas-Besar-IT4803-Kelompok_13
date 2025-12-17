#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED
#include "Paper.h"
#include <string>
#include <iostream>

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
adrR createElmR(adrPaper p);


// 103032430027 (Parent) point 1 & 7
void insertKeywordFirst(ListKeyword &LK, adrKey k); // done
void insertKeywordAfter(ListKeyword &LK, adrKey prec, adrKey k); // done
void insertKeywordLast(ListKeyword &LK, adrKey k); // done
adrKey findElmKey(ListKeyword LK, infotypeKey x); // done

//103032430018 (Parent) point 4 & 10
void deleteKeywordFirst(ListKeyword &LK, adrKey &k); // done
void deleteKeywordAfter(ListKeyword &LK, adrKey prec, adrKey &k); // done
void deleteKeywordLast(ListKeyword &LK, adrKey &k); // done
void showKey(ListKeyword LK); // done

//103032430027 (Relasi) point 6 & 12 & 14 & 16 & 19
void deleteRelation(ListKeyword LK, adrR r);  // point 6 // done
void viewPaperbyKeyword(ListKeyword LK, infotypeKey k); // point 12 // done
void countRelationOfKeyword(ListKeyword LK); // point 16 // done
void editRelation(ListKeyword LK, ListPaper LP, adrPaper p, adrKey newK, adrKey oldK); // point 19 // done
void showAllPaperAndKeyword(ListKeyword LK, ListPaper LP); // point 14

//103032430018 (Relasi) point 3 & 9 & 13 & 15 & 17 & 18
void insertRelation(ListKeyword LK, adrR r, adrPaper p); //insert last done
void viewKeywordbyPaper(ListKeyword LK, ListPaper LP, string p); // point 15
int countRelationOfPaper(ListKeyword LK, ListPaper LP); // point 17
void showAllKeywordAndPaper(ListKeyword LK, ListPaper LP); // point 13
int countNoRelationPaper(ListKeyword LK, ListPaper LP); // point 18

#endif // KEYWORD_H_INCLUDED

