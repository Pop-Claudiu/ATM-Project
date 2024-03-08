#include "C:\Users\Gabriel\Desktop\Cursuri + Carti\Lab OOP\Lab2SD\Test\Test_colectie.h"
#include "ATM.h"
#include "Colectie.h"
#include "Tranzactie.h"
#include "UI.h"

int main() {
    test_all();
    Colectie bancnote;
    for (int i = 0; i < 5; i++) {
        bancnote.add(1);
        bancnote.add(5);
        bancnote.add(10);
        bancnote.add(20);
        bancnote.add(50);
        bancnote.add(100);
        bancnote.add(200);
        bancnote.add(500);
    }
    ATM atm(bancnote);
    run_menu(atm, R"(C:\Users\Gabriel\Desktop\Cursuri + Carti\Lab OOP\Lab2SD\date.in)");
    return 0;
}
