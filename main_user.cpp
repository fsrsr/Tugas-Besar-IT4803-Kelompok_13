#include "main.h"
#include "Paper.h"
#include "Keyword.h"
#include <iostream>
#include "string"
using namespace std;

void menuUser(){
    int option=-99;
    ListKeyword LK;
    ListPaper LP;
    adrKey newK, oldK;
    adrPaper p;
    infotypeKey k;
    string x;
    int Cp, CnR;

    while (option != 0) {
        system("cls");
        cout << "=================== Menu Studi Kasus =================== " << endl;
        cout << "|| 1. Lihat paper dari keyword                         ||" << endl;
        cout << "|| 2. Lihat semua keyword dengan setiap papernya       ||" << endl;
        cout << "|| 3. Lihat semua paper dengan setiap keywordnya       ||" << endl;
        cout << "|| 4. Lihat keyword dari paper                         ||" << endl;
        cout << "|| 5. Hitung banyak paper dari setiap keyword          ||" << endl;
        cout << "|| 6. Hitung banyak keyword dari paper tertentu        ||" << endl;
        cout << "|| 7. Hitung banyak paper yang tidak memiliki keyword  ||" << endl;
        cout << "|| 8. Ubah paper dari suatu keyword                    ||" << endl;
        cout << "======================================================== " << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1  :
              cout << "=== LIHAT PAPER ===" << endl;
              cout << "Paper dengan keyword apa yang ingin dicari? ";
              cin >> k;
              viewPaperbyKeyword(LK, k);

              break;
           case 2  :
              cout << "=== LIHAT SEMUA KEYWORD DENGAN PAPER ===" << endl;
              showAllKeywordAndPaper(LK, LP);

              break;
           case 3  :
              cout << "=== LIHAT SEMUA PAPER DENGAN KEYWORD ===" << endl;
              showAllPaperAndKeyword(LK, LP);

              break;
           case 4  :
              cout << "=== LIHAT KEYWORD ===" << endl;
              cout << "Keyword dengan paper apa yang ingin dicari? ";
              cin >> x;
              viewKeywordbyPaper(LK, LP, x);

              break;
           case 5  :
              cout << "=== HITUNG BANYAK PAPER DI SETIAP KEYWORD ===" << endl;
              countRelationOfKeyword(LK);

              break;
           case 6  :
              cout << "=== HITUNG BANYAK KEYWORD DARI PAPER TERTENTU ===" << endl;
              Cp = countRelationOfPaper(LK, LP);
              cout << Cp;

              break;
           case 7  :
              cout << "=== HITUNG BANYAK PAPER TANPA KEYWORD ===" << endl;
              CnR = countNoRelationPaper(LK, LP);
              cout << CnR;

              break;
           case 8  :
              cout << "=== UBAH PAPER ===" << endl;
              editRelation(LK, LP, p, newK, oldK);

              break;
        }
    }
}
