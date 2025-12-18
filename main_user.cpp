#include "main.h"
#include "Paper.h"
#include "Keyword.h"
#include <iostream>
#include "string"
using namespace std;

void menuUser(ListKeyword &LK, ListPaper &LP){
    int option=-99;
    adrKey newK, oldK;
    adrPaper p;
    infotypeKey k, oldKey, newKey;
    string x, paperTitle;
    int Cp, CnR;

    while (option != 0) {
        system("cls");
        cout << "=================== Menu Studi Kasus ====================" << endl;
        cout << "|| 1. Cari paper dari keyword                          ||" << endl;
        cout << "|| 2. Cari keyword dari paper                          ||" << endl;
        cout << "|| 3. Lihat semua keyword dengan setiap papernya       ||" << endl;
        cout << "|| 4. Lihat semua paper dengan setiap keywordnya       ||" << endl;
        cout << "|| 5. Hitung banyak paper dari setiap keyword          ||" << endl;
        cout << "|| 6. Hitung banyak keyword dari paper tertentu        ||" << endl;
        cout << "|| 7. Hitung banyak paper yang tidak memiliki keyword  ||" << endl;
        cout << "|| 8. Ubah paper dari suatu keyword                    ||" << endl;
        cout << "|| 0. Kembali                                          ||" << endl;
        cout << "=========================================================" << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1  :
              cout << "=== LIHAT PAPER ===" << endl;
              cout << "Paper dengan keyword apa yang ingin dicari? ";
              cin >> k;
              viewPaperbyKeyword(LK, k);
              system("pause");

              break;
           case 2  :
              cout << "=== LIHAT KEYWORD ===" << endl;
              cout << "Keyword dengan paper apa yang ingin dicari? ";
              cin >> x;
              viewKeywordbyPaper(LK, LP, x);

              system("pause");

              break;
           case 3  :
              cout << "=== LIHAT SEMUA PAPER DENGAN KEYWORD ===" << endl;
              showAllPaperAndKeyword(LK, LP);
              system("pause");

              break;
           case 4  :
              cout << "=== LIHAT SEMUA KEYWORD DENGAN PAPER ===" << endl;
              showAllKeywordAndPaper(LK, LP);
              system("pause");

              break;
           case 5  :
              cout << "=== HITUNG BANYAK PAPER DI SETIAP KEYWORD ===" << endl;
              countRelationOfKeyword(LK);
              system("pause");

              break;
           case 6  :
              cout << "=== HITUNG BANYAK KEYWORD DARI PAPER TERTENTU ===" << endl;
              Cp = countRelationOfPaper(LK, LP);
              cout << "Jumlah keyword: " << Cp << endl;
              system("pause");

              break;
           case 7  :
              cout << "=== HITUNG BANYAK PAPER TANPA KEYWORD ===" << endl;
              CnR = countNoRelationPaper(LK, LP);
              cout << "Jumlah paper tanpa keyword: " << CnR << endl;
              system("pause");

              break;
           case 8  :
              cout << "=== UBAH KEYWORD DARI PAPER ===" << endl;
              cout << "Masukkan judul paper: ";
              cin >> paperTitle;

              p = findElmPaper(LP, paperTitle);

              if (p == nullptr) {
                  cout << "Paper tidak ditemukan!" << endl;
              } else {
                  cout << "Masukkan keyword lama: ";
                  cin >> oldKey;
                  oldK = findElmKey(LK, oldKey);

                  if (oldK == nullptr) {
                      cout << "Keyword lama tidak ditemukan!" << endl;
                  } else {
                      cout << "Masukkan keyword baru: ";
                      cin >> newKey;
                      newK = findElmKey(LK, newKey);

                      if (newK == nullptr) {
                          cout << "Keyword baru tidak ditemukan! Buat keyword terlebih dahulu." << endl;
                      } else {
                          editRelation(LK, LP, p, newK, oldK);
                      }
                  }
              }
              system("pause");

              break;
        }
    }
}
