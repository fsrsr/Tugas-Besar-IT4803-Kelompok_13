#include "main.h"
#include "Paper.h"
#include "Keyword.h"

void menuUser(){
    int option=-99;
    int option1 = -99;
    int option2 = -99;
    int option3 = -99;


    while (option != 0) {
            system("cls");
            cout << "========= Menu Kumpulan Paper ===========" << endl;
            cout << "|| 1. Cari Paper                       ||" << endl;
            cout << "|| 2. Tampil Paper yang ada            ||" << endl;
            cout << "|| 3. Tampil Keyword yang ada          ||" << endl;
            cout << "|| 4. Keluar                           ||" << endl;
            cout << "=========================================" << endl;
            cout << "Choose your option : ";
            cin >> option;

        switch(option) {
           case 1  :
                cout << "you choose option 1 ; Cari Paper" << endl;
                cout << endl;
                cout << "========= Cari Paper ===========" << endl;
                cout << "|| 1. Masukkan Keyword        ||" << endl;
                cout << "|| 2. Kembali                 ||" << endl;
                cout << "|| 3. Keluar                  ||" << endl;
                cout << "===============================" << endl;
                cout << "Choose your option : ";
                cin >> option1;

                while(option1 != 0){
                    switch(option1){
                        case 1 :
                                cout << "you choose option 1 ; Masukkan Keyword" << endl;
                                cout << endl;
                                cout << "========= Masukkan Keyword ==========" << endl;
                                cout << "|| Keyword :                       ||";
                                cin >> option1;
                                cout << "=====================================" << endl;

                                //....

                            break;

                        case 2 :
                                menuUser();
                            break;

                        case 3 :
                                return;
                            break;
                    }
                }


           case 2  :
                cout << "you choose option 2 ; Tampil Semua Paper yang ada" << endl;
                cout << endl;
                cout << "========= Tampil Semua Paper ===========" << endl;

                //... view all paper
                //... kasih tau total nya ada berapa

                cout << "|| 1. Kembali                         ||" << endl;
                cout << "|| 2. Keluar                          ||" << endl;
                cout << "========================================" << endl;
                cout << "Choose your option : ";
                cin >> option2;


                while(option2 != 0){
                   switch(option2){
                        case 1 :
                               menuUser();
                           break;

                        case 2 :
                               return;
                           break;

              break;

           case 3  :
                cout << "you choose option 3 ; Tampil Semua Keyword yang ada" << endl;
                cout << endl;
                cout << "========== Tampil Semua Keyword yang ada ==========" << endl;

               //... viewAllKey
               //... kasih total nya berapa

                cout << "|| 1. Kembali                                    ||" << endl;
                cout << "|| 2. Keluar                                     ||" << endl;
                cout << "===================================================" << endl;
                cout << "Choose your option : ";
                cin >> option3;

                while(option3 != 0){
                   switch(option3){
                        case 1 :
                               menuUser();
                            break;

                        case 2 :
                                return;
                            break;


              break;

           case 4 :
                return;

        }
    }
}


