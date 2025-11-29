#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED
#include "string"

typedef string infotypeKey;
typedef struct elmKey *adrKey;

struct elmP{
    infotypeKey infoKey;
    adrKey nextKey;
};

struct ListP{
    adrKey first;
};

createListKeyword_103032430027();
createElmKeyword_();


insertKeywordFirst_103032430027();
insertKeywordAfter_103032430027();
insertKeywordLast_103032430027();

deleteKeywordFirst_();
deleteKeywordAfter_();
deleteKeywordLast_();

findElmKey_103032430027();
viewKey_();

#endif // KEYWORD_H_INCLUDED
