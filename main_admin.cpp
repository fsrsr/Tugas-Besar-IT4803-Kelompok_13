#include "main.h"
#include "Paper.h"
#include "Keyword.h"
#include <iostream>
#include "string"
using namespace std;

void menuAdmin(ListKeyword &LK, ListPaper &LP){
    void menuParent(ListKeyword &LK, ListPaper &LP);
    void menuChild(ListPaper &LP);
    void menuRelation(ListKeyword &LK, ListPaper &LP);

    int option=-99999;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin ============" << endl;
        cout << "|| 1. Parent                      ||" << endl;
        cout << "|| 2. Child                       ||" << endl;
        cout << "|| 3. Relation                    ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuParent(LK, LP);
              continue;
           case 2  :
              cout << "you choose option 2" << endl;
              menuChild(LP);
              continue;
           case 3 :
              cout << "you choose option 3" << endl;
              menuRelation(LK, LP);
              continue;
        }
    }
}


void menuParent(ListKeyword &LK, ListPaper &LP){
    int option=-9999;
    infotypeKey keyword, key;
    adrKey precK, z, fKey;
    adrPaper cariPaper;
    string n;
    int x;

    while (option != 0) {
        system("cls");
        cout << "============ Menu Keyword =============" << endl;
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
        cout << endl;

        switch(option) {
           case 1  :
              cout << "=== INSERT FIRST ===" << endl;
              cout << "Masukkan keyword: ";
              cin >> keyword;

              z = createElmKeyword(keyword);
              insertKeywordFirst(LK, z);
              cout << "Keyword berhasil ditambahkan!" << endl;
              cout << endl;
              cout << "Hubungkan keyword ini ke paper yang sudah ada? " << endl;
              cout << "1. Ya" << endl;
              cout << "2. Tidak" << endl;
              cout << "Choose your option: ";
              cin >> x;

              if (x == 1) {
                  cout << "Masukkan judul paper: ";
                  cin >> n;

                  cariPaper = findElmPaper(LP, n);
                  if (cariPaper != nullptr) {
                      connect(z, cariPaper);
                  } else {
                      cout << "Paper tidak ditemukan!" << endl;
                  }
              }
              system("pause");

              break;
           case 2  :
              cout << "=== INSERT LAST ===" << endl;
              cout << "Masukkan keyword: ";
              cin >> keyword;

              z = createElmKeyword(keyword);
              insertKeywordLast(LK, z);
              cout << "Keyword berhasil ditambahkan!" << endl;
              cout << endl;
              cout << "Hubungkan keyword ini ke paper yang sudah ada? " << endl;
              cout << "1. Ya" << endl;
              cout << "2. Tidak" << endl;
              cout << "Choose your option: ";
              cin >> x;

              if (x == 1) {
                  cout << "Masukkan judul paper: ";
                  cin >> n;

                  cariPaper = findElmPaper(LP, n);
                  if (cariPaper != nullptr) {
                      connect(z, cariPaper);
                  } else {
                      cout << "Paper tidak ditemukan!" << endl;
                  }

              system("pause");

              break;
           case 3:
              cout << "=== INSERT AFTER ===" << endl;
              cout << "Insert setelah keyword apa? ";
              cin >> key;

              precK = findElmKey(LK, key);

              if (precK == nullptr) {
                  cout << "Keyword \"" << key << "\" tidak ditemukan!" << endl;
                  cout << "Insert after gagal!" << endl;
              } else {
                  cout << "Masukkan keyword baru yang akan ditambahkan: ";
                  cin >> keyword;

                  z = createElmKeyword(keyword);
                  insertKeywordAfter(LK, precK, z);
                  cout << "Keyword \"" << keyword << "\" berhasil ditambahkan setelah \"" << key << "\"!" << endl;
              }
              cout << endl;
             /* cout << "Hubungkan keyword ini ke paper yang sudah ada? " << endl;
              cout << "1. Ya" << endl;
              cout << "2. Tidak" << endl;
              cout << "Choose your option: ";
              cin >> x;

              if (x == 1) {
                  cout << "Masukkan judul paper: ";
                  cin >> n;

                  cariPaper = findElmPaper(LP, n);
                  if (cariPaper != nullptr) {
                      connect(z, cariPaper);
                  } else {
                      cout << "Paper tidak ditemukan!" << endl;
                  }
              }*/

              system("pause");

              break;
           case 4:
              cout << "=== DELETE FIRST ===" << endl;
              deleteKeywordFirst(LK, z);
              if (z != nullptr) {
                  cout << "Keyword " << z->info << " berhasil dihapus!" << endl;
                  delete z;
              }
              system("pause");

              break;
           case 5:
              cout << "=== DELETE LAST ===" << endl;
              deleteKeywordLast(LK, z);
              if (z != nullptr) {
                  cout << "Keyword " << z->info << " berhasil dihapus!" << endl;
                  delete z;
              }
              system("pause");

              break;
           case 6:
              cout << "=== DELETE AFTER ===" << endl;
              cout << "Masukkan keyword yang akan dicari: ";
              cin >> key;

              precK = findElmKey(LK, key);

              if (precK == nullptr) {
                  cout << "Keyword " << key << " tidak ditemukan!" << endl;
              } else {
                  deleteKeywordAfter(LK, precK, z);
                  if (z != nullptr) {
                      cout << "Keyword " << z->info << " berhasil dihapus!" << endl;
                      delete z;
                  }
              }
              system("pause");

              break;
           case 7:
              cout << "=== CARI KEYWORD ===" << endl;
              cout << "Masukkan keyword yang ingin dicari: ";
              cin >> key;
              fKey = findElmKey(LK, key);

              if (fKey != nullptr) {
                  cout << "Keyword \"" << fKey->info << "\" ditemukan!" << endl;
              } else {
                  cout << "Keyword \"" << key << "\" tidak ditemukan!" << endl;
              }
              system("pause");

              break;
           case 8:
              cout << "=== LIHAT SEMUA KEYWORD ===" << endl;
              showKey(LK);
              system("pause");

              break;
            }
        }
    }
}


void menuChild(ListPaper &LP){
    int option=-9999;
    infotypePaper paper, p;
    adrPaper precP, q, fPaper;
    string x;

    while (option != 0) {
        system("cls");
        cout << "============ Menu Paper ============ " << endl;
        cout << "|| 1. Insert First                 ||" << endl;
        cout << "|| 2. Insert Last                  ||" << endl;
        cout << "|| 3. Insert After                 ||" << endl;
        cout << "|| 4. Delete First                 ||" << endl;
        cout << "|| 5. Delete Last                  ||" << endl;
        cout << "|| 6. Delete After                 ||" << endl;
        cout << "|| 7. Find Paper                   ||" << endl;
        cout << "|| 8. Show All Paper               ||" << endl;
        cout << "|| 0. back                         ||" << endl;
        cout << "=====================================" << endl;
        cout << "Choose your option: ";
        cin >> option;
        cout << endl;

        switch(option) {
           case 1  :
              cout << "=== INSERT FIRST ===" << endl;
              cout << "Masukkan judul paper: ";
              cin >> paper.title;
              cout << "Masukkan penulis: ";
              cin >> paper.author;
              cout << "Masukkan tahun: ";
              cin >> paper.year;
              cout << "Masukkan kategori: ";
              cin >> paper.category;

              q = createElmPaper(paper);
              insertPaperFirst(LP, q);
              cout << "Paper berhasil ditambahkan!" << endl;
              system("pause");

              break;
           case 2  :
              cout << "=== INSERT LAST ===" << endl;
              cout << "Masukkan judul paper: ";
              cin >> paper.title;
              cout << "Masukkan penulis: ";
              cin >> paper.author;
              cout << "Masukkan tahun: ";
              cin >> paper.year;
              cout << "Masukkan kategori: ";
              cin >> paper.category;

              q = createElmPaper(paper);
              insertPaperLast(LP, q);
              cout << "Paper berhasil ditambahkan!" << endl;
              system("pause");

              break;
           case 3  :
              cout << "=== INSERT AFTER ===" << endl;
              cout << "Operasi Insert dilakukan setelah Paper judul Apa?: ";
              cin >> x;
              precP = findElmPaper(LP, x);

              if (precP == nullptr) {
                  cout << "Paper dengan judul \"" << x << "\" tidak ditemukan!" << endl;
              } else {
                  cout << "Masukkan judul paper baru: ";
                  cin >> paper.title;
                  cout << "Masukkan penulis: ";
                  cin >> paper.author;
                  cout << "Masukkan tahun: ";
                  cin >> paper.year;
                  cout << "Masukkan kategori: ";
                  cin >> paper.category;

                  q = createElmPaper(paper);
                  insertPaperAfter(LP, precP, q);
                  cout << "Paper berhasil ditambahkan!" << endl;
              }
              system("pause");

              break;
           case 4:
              cout << "=== DELETE FIRST ===" << endl;
              deletePaperFirst(LP, q);
              if (q != nullptr) {
                  cout << "Paper \"" << q->info.title << "\" berhasil dihapus!" << endl;
                  delete q;
              }
              system("pause");

              break;
           case 5:
              cout << "=== DELETE LAST ===" << endl;
              deletePaperLast(LP, q);
              if (q != nullptr) {
                  cout << "Paper \"" << q->info.title << "\" berhasil dihapus!" << endl;
                  delete q;
              }
              system("pause");

              break;
           case 6:
              cout << "=== DELETE AFTER ===" << endl;
              cout << "Operasi Delete dilakukan setelah Paper judul Apa?: ";
              cin >> x;
              precP = findElmPaper(LP, x);

              if (precP == nullptr) {
                  cout << "Paper dengan judul \"" << x << "\" tidak ditemukan!" << endl;
              } else {
                  deletePaperAfter(LP, precP, q);
                  if (q != nullptr) {
                      cout << "Paper \"" << q->info.title << "\" berhasil dihapus!" << endl;
                      delete q;
                  }
              }
              system("pause");

              break;
           case 7:
              cout << "=== CARI PAPER ===" << endl;
              cout << "Masukkan judul paper yang ingin dicari: ";
              cin >> x;

              fPaper = findElmPaper(LP, x);

              if (fPaper != nullptr) {
                  cout << "Paper ditemukan!" << endl;
                  cout << "Judul: " << fPaper->info.title << endl;
                  cout << "Penulis: " << fPaper->info.author << endl;
                  cout << "Tahun: " << fPaper->info.year << endl;
                  cout << "Kategori: " << fPaper->info.category << endl;
              } else {
                  cout << "Paper \"" << x << "\" tidak ditemukan!" << endl;
              }
              system("pause");

              break;
           case 8:
              cout << "=== LIHAT SEMUA PAPER ===" << endl;
              showPaper(LP);
              system("pause");

              break;
        }
    }
}

void menuRelation(ListKeyword &LK, ListPaper &LP){

    int option = -9999;
    string keywordStr, paperTitle;
    adrKey keyword;
    adrPaper paper;
    adrR relation;

    while (option != 0) {
        system("cls");
        cout << "============ Menu Relasi ==============" << endl;
        cout << "|| 1. Hubungkan Keyword ke Paper     ||" << endl;
        cout << "|| 2. Hubungkan Paper ke Keyword     ||" << endl;
        cout << "|| 3. Putuskan Relasi Keyword->Paper ||" << endl;
        cout << "|| 4. Putuskan Relasi Paper->Keyword ||" << endl;
        cout << "|| 0. Kembali                        ||" << endl;
        cout << "=======================================" << endl;
        cout << "Choose your option: ";
        cin >> option;
        cout << endl;

        switch(option) {
            case 1: {
                cout << "=== HUBUNGKAN KEYWORD KE PAPER ===" << endl;

                cout << "\nDaftar Keyword yang tersedia:" << endl;
                showKey(LK);

                cout << "\nMasukkan keyword yang ingin dihubungkan: ";
                cin >> keywordStr;

                keyword = findElmKey(LK, keywordStr);
                if (keyword == nullptr) {
                    cout << "Keyword tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                cout << "\nDaftar Paper yang tersedia:" << endl;
                showPaper(LP);

                cout << "\nMasukkan judul paper yang ingin dihubungkan: ";
                cin >> paperTitle;

                paper = findElmPaper(LP, paperTitle);
                if (paper == nullptr) {
                    cout << "Paper tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                connect(keyword, paper);

                system("pause");
                break;
            }

            case 2: {
                cout << "=== HUBUNGKAN PAPER KE KEYWORD ===" << endl;

                cout << "\nDaftar Paper yang tersedia:" << endl;
                showPaper(LP);

                cout << "\nMasukkan judul paper yang ingin dihubungkan: ";
                cin >> paperTitle;

                paper = findElmPaper(LP, paperTitle);
                if (paper == nullptr) {
                    cout << "Paper tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                cout << "\nDaftar Keyword yang tersedia:" << endl;
                showKey(LK);

                cout << "\nMasukkan keyword yang ingin dihubungkan: ";
                cin >> keywordStr;

                keyword = findElmKey(LK, keywordStr);
                if (keyword == nullptr) {
                    cout << "Keyword tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                connect(keyword, paper);

                system("pause");
                break;
            }

            case 3: {
                cout << "=== PUTUSKAN RELASI KEYWORD->PAPER ===" << endl;

                cout << "\nDaftar Keyword yang tersedia:" << endl;
                showKey(LK);

                cout << "\nMasukkan keyword: ";
                cin >> keywordStr;

                keyword = findElmKey(LK, keywordStr);
                if (keyword == nullptr) {
                    cout << "Keyword tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                cout << "\nPaper yang terhubung dengan Keyword '" << keywordStr << "':" << endl;
                adrR r = keyword->firstR;
                if (r == nullptr) {
                    cout << "  (Tidak ada paper yang terhubung)" << endl;
                    system("pause");
                    break;
                } else {
                    int count = 1;
                    while (r != nullptr) {
                        cout << "  " << count << ". " << r->infoRP->info.title << endl;
                        r = r->nextR;
                        count++;
                    }
                }

                cout << "\nMasukkan judul paper yang ingin diputuskan: ";
                cin >> paperTitle;

                paper = findElmPaper(LP, paperTitle);
                if (paper == nullptr) {
                    cout << "Paper tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                relation = findElmR(LK, paper);
                if (relation == nullptr) {
                    cout << "Tidak ada relasi antara keyword '" << keywordStr
                         << "' dan paper '" << paperTitle << "'" << endl;
                } else {
                    deleteRelation(LK, relation);
                    cout << "Berhasil memutuskan relasi antara keyword '" << keywordStr << "' dan paper '" << paperTitle << "'" << endl;
                }

                system("pause");
                break;
            }

            case 4: {
                cout << "=== PUTUSKAN RELASI PAPER->KEYWORD ===" << endl;

                cout << "\nDaftar Paper yang tersedia:" << endl;
                showPaper(LP);

                cout << "\nMasukkan judul paper: ";
                cin >> paperTitle;

                paper = findElmPaper(LP, paperTitle);
                if (paper == nullptr) {
                    cout << "Paper tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                cout << "\nKeyword yang terhubung dengan Paper '" << paperTitle << "':" << endl;
                adrKey k = LK.first;
                bool hasRelation = false;

                while (k != nullptr) {
                    adrR r = k->firstR;
                    while (r != nullptr) {
                        if (r->infoRP == paper) {
                            cout << "  - " << k->info << endl;
                            hasRelation = true;
                            break;
                        }
                        r = r->nextR;
                    }
                    k = k->next;
                }

                if (!hasRelation) {
                    cout << "  (Tidak ada keyword yang terhubung)" << endl;
                    system("pause");
                    break;
                }

                cout << "\nMasukkan keyword yang ingin diputuskan: ";
                cin >> keywordStr;

                keyword = findElmKey(LK, keywordStr);
                if (keyword == nullptr) {
                    cout << "Keyword tidak ditemukan!" << endl;
                    system("pause");
                    break;
                }

                relation = nullptr;
                k = LK.first;
                while (k != nullptr) {
                    if (k == keyword) {
                        adrR r = k->firstR;
                        while (r != nullptr) {
                            if (r->infoRP == paper) {
                                relation = r;
                                break;
                            }
                            r = r->nextR;
                        }
                        break;
                    }
                    k = k->next;
                }

                if (relation == nullptr) {
                    cout << "Keyword '" << keywordStr << "' tidak terhubung dengan paper '" << paperTitle << "'" << endl;
                } else {
                    deleteRelation(LK, relation);
                    cout << "Berhasil memutuskan relasi antara paper '"
                         << paperTitle << "' dan keyword '" << keywordStr << "'" << endl;
                }

                system("pause");
                break;
            }
        }
    }
}
