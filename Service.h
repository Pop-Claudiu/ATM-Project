

#include "ATM.h"

#ifndef LAB2SD_SERVICE_H
#define LAB2SD_SERVICE_H

#endif //LAB2SD_SERVICE_H

void service_depunere(int id_tranzactie, int suma, int *lista_bancnote, int lenght, ATM &atm);
void service_retragere(int id_tranzactie, int* lista_bancnote, int lenght, ATM& atm);
void readFile(string fileName, ATM& atm);
void updateFile(string fileName, ATM&atm);