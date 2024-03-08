//
// Created by Gabriel on 3/28/2023.
//

#ifndef LAB2SD_TRANZACTIE_H
#define LAB2SD_TRANZACTIE_H

#include "Colectie.h"
#include <iostream>

using namespace std;

class Tranzactie {
private:
    int id_tranzactie;
    int suma;
public:
    Colectie bancnote_tranzactie;
    int getId() {return id_tranzactie;}
    int getSuma() {return suma;}
    Colectie getColectie() {return bancnote_tranzactie;}
    Tranzactie();
    Tranzactie(int id_tranzactie, int suma, Colectie& bancnote_tranzactie);
    ~Tranzactie();
    Colectie get_bancnote_tranzactie();
    friend ostream& operator<<(ostream& os, Tranzactie& tr);

};


#endif //LAB2SD_TRANZACTIE_H
