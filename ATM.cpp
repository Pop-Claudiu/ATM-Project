

#include "ATM.h"
#include <iostream>


ATM::ATM(Colectie& bancnote) {
    CAP = 20; no_transactions = 0;
    this -> bancnote = bancnote;
    tranzactii = new Tranzactie[CAP];
}

ATM::~ATM() {
    delete[] tranzactii; tranzactii = nullptr;
}

void ATM::resize_tranzactii() {
    CAP *= 2;
    Tranzactie* new_transactions;
    new_transactions = new Tranzactie[CAP];
    for (int i = 0; i < no_transactions; i++) {
        new_transactions[i] = tranzactii[i];
    }
    delete[] tranzactii;
    tranzactii = new_transactions;
}

void ATM::add_tranzactie(Tranzactie &tranzactie, Colectie &bancnote_colectie) {
    if(no_transactions + 1 > CAP) resize_tranzactii();
    tranzactii[no_transactions++] = tranzactie;
    for (int i = 0; i < bancnote_colectie.size_colectie(); i++) {
        for (int j = 0; j < bancnote_colectie.nroccurrences(bancnote_colectie.getAt(i)); j++)
            bancnote.add(bancnote_colectie.getAt(i));
    }
}

ostream &operator<<(ostream &os, ATM &atm) {
    cout << "Numar tranzactii: " << atm.no_transactions << endl;
    cout << "Tranzactiile sunt: " << endl;
    for (int i = 0; i < atm.no_transactions; i++) {
        cout << atm.tranzactii[i];
    }
    cout << "----------" << endl;
    cout << "Sold bancomat: " << atm.sold() << endl;
    cout << atm.bancnote;
    return os;
}


Colectie& ATM::get_colectie() {
    return bancnote;
}

int ATM::sold() {
    return bancnote.sum();
}

void ATM::extragere(Tranzactie &tranzactie, Colectie &bancnote_colectie) {
    if(no_transactions + 1 > CAP) resize_tranzactii();
    tranzactii[no_transactions++] = tranzactie;
    int size = bancnote_colectie.size_colectie();
    for (int i = 0; i < size; i++) {
        int bancnota = bancnote_colectie.getAt(i);
        for (int j = 0; j < bancnote_colectie.nroccurrences(bancnota); j++) {
            bancnote.remove(bancnota);
        }
    }
}

ATM::ATM() = default;
