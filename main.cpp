#include <iostream>
#include "main.h"
using namespace std;

int main(){
    int option = -99;
    while (option != 0) {
            system("cls");
            cout << "========= SELAMAT DATANG DI PENCARIAN PAPER ===========" << endl;
            cout << "===========                              =============" << endl;
            cout << "=================== Mode Apa? =========================" << endl;
            cout << "|| 1. Admin                                          ||" << endl;
            cout << "|| 2. User                                           ||" << endl;
            cout << "|| 3. Keluar                           ||" << endl;
            cout << "=========================================" << endl;
            cout << "Choose your option : ";
            cin >> option;
        switch(option) {
           case 1   :
                    menuAdmin();
                    break;
           case 2   :
                    menuUser();
                    break;
           case 3   :
                    return;

}
