//
// Created by Gabriel on 3/28/2023.
//

#ifndef LAB2SD_ATM_H
#define LAB2SD_ATM_H

#include "Colectie.h"
#include "Tranzactie.h"
#include <iostream>

using namespace std;

class ATM {
    //friend Extragere;
private:
    int CAP;
    int no_transactions;
    Tranzactie* tranzactii;
    void resize_tranzactii();
public:
    Colectie bancnote;
    ATM();
    ATM(Colectie& bancnote);
    ~ATM();
    void add_tranzactie(Tranzactie &tranzactie, Colectie &bancnote_colectie);
    void extragere(Tranzactie &tranzactie, Colectie& bancnote_extragere);
    friend ostream& operator<<(ostream& os, ATM& atm);
    Colectie& get_colectie();
    int sold();
    Tranzactie* getTranzactie() {return tranzactii;}
    int sizeTranz() {return no_transactions;}

};


#endif //LAB2SD_ATM_H
