#include "main.h"
#include "Paper.h"
#include "Keyword.h"
#include <iostream>
#include "string"
using namespace std;

void menuAdmin(){
    void menuParent();
    void menuChild();

    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin============ " << endl;
        cout << "|| 1. Parent                      ||" << endl;
        cout << "|| 2. Child                       ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuParent();
              continue;
           case 2  :
              cout << "you choose option 2" << endl;
              menuChild();
              continue;
        }
    }
}


void menuParent(){
    int option=-99;
    infotypeKey keyword, key;
    adrKey precK, z, fKey;
    ListKeyword LK;

    createListKeyword(LK);

    while (option != 0) {
        system("cls");
        cout << "============ Menu Keyword ============ " << endl;
        cout << "|| 1. Insert First                   ||" << endl;
        cout << "|| 2. Insert Last                    ||" << endl;
        cout << "|| 3. Insert After                   ||" << endl;
        cout << "|| 4. Delete First                   ||" << endl;
        cout << "|| 5. Delete Last                    ||" << endl;
        cout << "|| 6. Delete After                   ||" << endl;
        cout << "|| 7. Find Keyword                   ||" << endl;
        cout << "|| 8. Show All Keyword               ||" << endl;
        cout << "|| 0. back                           ||" << endl;
        cout << "=======================================" << endl;
        cout << "Choose your option: ";
        cin >> option;

        switch(option) {
           case 1  :
              cout << "=== INSERT FIRST ===" << endl;
              cout << "Masukkan keyword: ";
              cin >> keyword;

              z = createElmKeyword(keyword);
              insertKeywordFirst(LK, z);

              break;
           case 2  :
              cout << "=== INSERT LAST ===" << endl;
              cout << "Masukkan keyword: ";
              cin >> keyword;

              z = createElmKeyword(keyword);
              insertKeywordLast(LK, z);

              break;
           case 3:
              cout << "=== INSERT AFTER ===" << endl;
              cout << "Masukkan keyword: ";
              cin >> keyword;

              z = createElmKeyword(keyword);
              precK = findElmKey(LK, key);
              insertKeywordAfter(LK, precK, z);

              break;
           case 4:
              cout << "=== DELETE FIRST ===" << endl;
              deleteKeywordFirst(LK, z);

              break;
           case 5:
              cout << "=== DELETE LAST ===" << endl;
              deleteKeywordLast(LK, z);

              break;
           case 6:
              cout << "=== DELETE AFTER ===" << endl;
              precK = findElmKey(LK, key);
              deleteKeywordAfter(LK, precK, z);

              break;
           case 7:
              cout << "=== CARI KEYWORD ===" << endl;
              cout << "Masukkan keyword yang ingin dicari: ";
              cin >> key;
              fKey = findElmKey(LK, key);

              if (fKey != nullptr) {
                  cout << "Keyword " << fKey << " ditemukan!" << endl;
              } else {
                  cout << "Keyword " << fKey << " tidak ditemukan!" << endl;
              }

              break;
           case 8:
              cout << "=== LIHAT SEMUA KEYWORD ===" << endl;
              showKey(LK);

              break;
        }
    }
}

void menuChild(){
    int option=-99;
    ListPaper LP;
    infotypePaper paper, p;
    adrPaper precP, q, fPaper;
    string x;

    createListPaper(LP);

    while (option != 0) {
        system("cls");
        cout << "============ Menu Keyword ============ " << endl;
        cout << "|| 1. Insert First                   ||" << endl;
        cout << "|| 2. Insert Last                    ||" << endl;
        cout << "|| 3. Insert After                   ||" << endl;
        cout << "|| 4. Delete First                   ||" << endl;
        cout << "|| 5. Delete Last                    ||" << endl;
        cout << "|| 6. Delete After                   ||" << endl;
        cout << "|| 7. Find Paper                     ||" << endl;
        cout << "|| 8. Show All Paper                 ||" << endl;
        cout << "|| 0. back                           ||" << endl;
        cout << "=======================================" << endl;
        cout << "Choose your option: ";
        cin >> option;

        switch(option) {
           case 1  :
              cout << "=== INSERT FIRST ===" << endl;
              cout << "Masukkan paper yang ingin ditambahkan: ";
              cin >> paper.title;
              cin >> paper.author;
              cin >> paper.year;
              cin >> paper.category;

              q = createElmPaper(paper);
              insertPaperFirst(LP, q);

              break;
           case 2  :
              cout << "=== INSERT LAST ===" << endl;
              cout << "Masukkan paper yang ingin ditambahkan: ";
              cin >> paper.title;
              cin >> paper.author;
              cin >> paper.year;
              cin >> paper.category;

              q = createElmPaper(paper);
              insertPaperLast(LP, q);

              break;
           case 3  :
              cout << "=== INSERT AFTER ===" << endl;
              cout << "Masukkan paper yang ingin ditambahkan: ";
              cin >> paper.title;
              cin >> paper.author;
              cin >> paper.year;
              cin >> paper.category;

              q = createElmPaper(paper);
              cout << "Operasi Insert dilakukan setelah Paper judul Apa?: " << endl;
              cin >> x;
              precP = findElmPaper(LP, x);
              insertPaperAfter(LP, precP, q);

              break;
           case 4:
              cout << "=== DELETE FIRST ===" << endl;
              deletePaperFirst(LP, q);

              break;
           case 5:
               cout << "=== DELETE LAST ===" << endl;
              deletePaperLast(LP, q);

              break;
           case 6:
              cout << "=== DELETE AFTER ===" << endl;
              cout << "Operasi Delete dilakukan setelah Paper judul Apa?: " << endl;
              cin >> x;
              precP = findElmPaper(LP, x);
              deletePaperAfter(LP, precP, q);

              break;
           case 7:
              cout << "=== CARI PAPER ===" << endl;
              cout << "Nama paper yang ingin dicari: ";
              cin >> paper.title;
              cin >> paper.author;
              cin >> paper.year;
              cin >> paper.category;

              fPaper = findElmPaper(LP, paper.title);

              if (fPaper != nullptr) {
                  cout << "Paper " << fPaper << " ditemukan!" << endl;
              } else {
                  cout << "Paper " << fPaper << " tidak ditemukan!" << endl;
              }
        }
    }
}
