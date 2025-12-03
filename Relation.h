#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "Keyword.h"

typedef struct elmR *adrR;
struct elmR{
    adrR nextR;
    adrKey infoRC;
};

createElmR(adrKey ...)
{
    infoRC = kryword
    nrxtR = nullptr
}


//insertRelation(adrkey  k, adrpaper p){
    //r = createElmR(k) // buat elm relationnya
    //menghubungkan paper ke keyword
     //baru insert

    //if p->firstR == null{
            //insertfirst
    //else
        //insertlast
        //depan insertfirts, belakang last, dst. (all di paper child dan relation)
//}
//insertRFirst_103032430027(adrPaper p, adrR relation){
    //P->firstR = relation
//}
//insertRAfter_103032430027(); //parameternya ada adrKey dan adrPaper (all insert)
//insertRLast_103032430027(adrPaper p, adrR relation){
    //adrR x = p->firstR;
    //while x->nextR != nullptr{
        //x = x->next
    //}
    //x->next = relation
//}

deleteRFirst_();

deleteRAfter_();
deleteRLast_();

findElmR_103032430027();
viewR_();


#endif // RELATION_H_INCLUDED


// menu
// user masukin judul paper dan isinya
// nanya ke user, keyword satu satu

// kalo keyword udh ada yaudah, kalo blm create trus dimasukin ke list keyword
