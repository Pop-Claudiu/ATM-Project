//
// Created by Gabriel on 3/28/2023.
//

#include <fstream>
#include "Service.h"
#include "Colectie.h"
#include "Tranzactie.h"
#include "ATM.h"

void readFile(string fileName, ATM& atm) {
    ifstream fin(fileName);
    int idTranzactie, suma, lenght;
    int listaBancnote[20];
    while(fin >> idTranzactie >> suma >> lenght) {
        int i = 0;
        while(i < lenght)
            fin >> listaBancnote[i++];
        service_depunere(idTranzactie, suma, listaBancnote, lenght, atm);
    }
    fin.close();
}

void updateFile(string fileName, ATM& atm) {
    ofstream fout(fileName, ofstream::out | ofstream::trunc);
    Tranzactie* tranz = atm.getTranzactie();
    for (int i = 0; i < atm.sizeTranz(); i++) {
        Colectie* colectie = &tranz[i].bancnote_tranzactie;
        fout << tranz[i].getId() << " " << tranz[i].getSuma() << " " << colectie->size_colectie() << " ";
        for (int j = 0; j < colectie->size_colectie(); j++) {
            fout << colectie->getAt(j) << " ";
        }
        fout << endl;
    }
    fout.close();
}

void service_depunere(int id_tranzactie, int suma, int *lista_bancnote, int lenght, ATM &atm) {
    Colectie colectie;
    for (int i = 0; i < lenght; i++) {
        colectie.add(lista_bancnote[i]);
    }
    Tranzactie tranzactie(id_tranzactie, suma, colectie);
    atm.add_tranzactie(tranzactie, colectie);
}

void service_retragere(int id_tranzactie, int* lista_bancnote, int lenght, ATM& atm) {
    Colectie colectie;
    for (int i = 0; i < lenght; i++) {
        colectie.add(lista_bancnote[i]);
    }
    int suma = colectie.sum();
    Tranzactie tranzactie(id_tranzactie, suma, colectie);
    atm.extragere(tranzactie, colectie);
}
