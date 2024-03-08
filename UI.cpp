//
// Created by Gabriel on 3/28/2023.
//

#include <iostream>
#include "UI.h"
#include "Service.h"

Colectie colectie_actuala;

void backtracking(int k, int suma, int size, Colectie& bancnote, int start_poz);
void extragere(ATM &atm, int id_extragere);
void afisare(ATM &atm);
void depunere(int id_tranzactie, ATM &atm);
bool ok(Colectie colectie, ATM &atm);
bool valid(ATM &atm);

using namespace std;

void print_menu() {
    cout << "       1 - Depunere" << endl;
    cout << "       2 - Extragere" << endl;
    cout << "       3 - Afisare" << endl;
    cout << "       x - Iesire din aplicatie" << endl;
}

void run_menu(ATM &atm, string fileName) {
    readFile(fileName, atm);
    int id_depunere = 0;
    int id_extragere = 0;
    print_menu();
    int optiune;
    while(scanf("%d", &optiune)) {
        if(optiune == 1) depunere(++id_depunere, atm);
        else if(optiune == 2) extragere(atm, --id_extragere);
        else if(optiune == 3) cout << atm;
        else cout << "Optiune gresita!";
        print_menu();
    }
    cout << "Iesire din aplicatie...";
    updateFile(fileName, atm);
}

void depunere(int id_tranzactie, ATM &atm) {
    cout << "Introduceti numarul bancnotelor: ";
    int n; cin >> n;
    cout << "Introduceti tipul bancnotelor: ";
    int lista_bancnote[20];
    int suma = 0;
    for (int i = 0; i < n; i++){
        cin >> lista_bancnote[i];
        suma += lista_bancnote[i];
    }
    service_depunere(id_tranzactie, suma, lista_bancnote, n, atm);
}

void extragere(ATM &atm, int id_extragere) {
    cout << "Introduceti suma pe care doriti sa o extrageti: ";
    int suuma; cin >> suuma;
    if (suuma > atm.sold()) cout << "ATM-ul nu dispune de aceasta suma!" << endl;
    else {
        Colectie bancnote;
        bancnote = atm.get_colectie();
        backtracking(0, suuma, bancnote.size_colectie(), bancnote, 0);
        int size;
        cout << "Introduceti numarul bancnotelor: ";
        cin >> size;
        cout << "Introduceti bancnotele pe care doriti sa le extrageti: ";
        int lista_bancnote[20];
        for (int i = 0; i < size; i++) {
            cin >> lista_bancnote[i];
        }
        service_retragere(id_extragere, lista_bancnote, size, atm);
    }
}

bool ok(Colectie& bancnote, int suma) {
    if(colectie_actuala.sum() > suma) return false;
    int size_col_actuala = colectie_actuala.size_colectie();
    for (int i = 0; i < size_col_actuala; i++) {
        int colectie_actuala_elem = colectie_actuala.getAt(i);
        int bancnote_elem = bancnote.getAt(i);
        if(colectie_actuala.nroccurrences(colectie_actuala_elem) > bancnote.nroccurrences(bancnote_elem)) return false;
        if(i < size_col_actuala - 1){
            if(colectie_actuala.getAt(i) > colectie_actuala.getAt(i + 1)) return false; //Doar cele crescatoare
        }
    }
    return true;
}


bool valid(int suma) {
    return colectie_actuala.sum() == suma;
}

void backtracking(int k, int suma, int size, Colectie& bancnote, int start_poz) {
    //start_poz este pentru ca modalitatile de extragere afisate sa fie unice
    for (int i = start_poz; i < size; i++) {
        int elemento = bancnote.getAt(i);
        colectie_actuala.add(elemento);
        if(ok(bancnote, suma)) {
            if(valid(suma))
                cout << colectie_actuala << endl;
            else
                backtracking(k + 1, suma, size, bancnote, i);
        }
        colectie_actuala.remove(elemento);
    }
}
