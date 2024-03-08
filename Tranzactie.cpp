//
// Created by Gabriel on 3/28/2023.
//

#include "Tranzactie.h"


Tranzactie::Tranzactie(int id_tranzactie, int suma, Colectie &bancnote_tranzactie) {
    this->id_tranzactie = id_tranzactie;
    this->suma = suma;
    this->bancnote_tranzactie = bancnote_tranzactie;
}

Tranzactie::~Tranzactie() = default;

Colectie Tranzactie::get_bancnote_tranzactie() {
    return this->bancnote_tranzactie;
}

ostream &operator<<(ostream &os, Tranzactie &tr) {
    if(tr.id_tranzactie < 0) cout << "   Id: " << tr.id_tranzactie << " (Extragere)" << endl;
    else cout << "   Id: " << tr.id_tranzactie << " (Depunere)" << endl;
    cout << "   Suma: " << tr.suma << endl;
    cout << tr.bancnote_tranzactie;
    cout << endl;
    return os;
}

Tranzactie::Tranzactie() = default;