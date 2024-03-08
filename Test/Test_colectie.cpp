//
// Created by Gabriel on 3/28/2023.
//

#include "C:\Users\Gabriel\Desktop\Cursuri + Carti\Lab OOP\Lab2SD\Colectie.h"
#include <cassert>
#include <iostream>


void test_add() {
    Colectie colectie;
    Colectie colectie1;
    colectie.add(4);
    colectie.add(5);
    colectie.add(4);
    colectie.add(7);
    colectie.add(4);
    colectie.add(11);
    colectie.add(4);
    colectie.add(11);
    colectie.add(0);
    colectie1 = colectie;
    assert(colectie.getAt(0) == 4);
    assert(colectie.nroccurrences(4) == 4);
    assert(colectie.getAt(4) == 0);
    assert(colectie.nroccurrences(0) == 1);
    assert(colectie1.getAt(0) == 4);
    assert(colectie1.nroccurrences(4) == 4);
    assert(colectie1.getAt(4) == 0);
    assert(colectie1.nroccurrences(0) == 1);
    Colectie colectie2;
    colectie2.add(1);
    colectie2.add(1);
    colectie2.add(1);
    colectie2.add(1);
    colectie2.add(1);
    colectie2.add(1);
    assert(colectie2.nroccurrences(1) == 6);
}

void test_remove() {
    Colectie colectie;
    colectie.add(4);
    colectie.add(5);
    colectie.add(4);
    colectie.add(7);
    colectie.add(4);
    colectie.add(11);
    colectie.add(4);
    colectie.add(11);
    colectie.add(0);
    colectie.remove(4);
    assert(colectie.nroccurrences(4) == 3);
    colectie.remove(5);
    assert(colectie.nroccurrences(5) == 0);
    assert(colectie.getAt(1) == 7);
}

void test_search() {
    Colectie colectie;
    colectie.add(4);
    colectie.add(5);
    colectie.add(4);
    colectie.add(7);
    colectie.add(4);
    colectie.add(11);
    colectie.add(4);
    colectie.add(11);
    colectie.add(0);
    colectie.remove(4);
    assert(colectie.search(56) == -1);
    assert(colectie.search(4) == 0);
    assert(colectie.search(7) == 2);
}

void test_size_occ_get() {
    Colectie colectie;
    assert(colectie.size_colectie() == 0);
    colectie.add(4);
    colectie.add(5);
    colectie.add(4);
    colectie.add(7);
    colectie.add(4);
    colectie.add(11);
    colectie.add(4);
    colectie.add(11);
    colectie.add(0);
    assert(colectie.size_colectie() == 5);
    assert(colectie.nroccurrences(4) == 4);
    assert(colectie.getAt(2) == 7);
}

void test_all() {
    test_add();
    test_remove();
    test_search();
    test_size_occ_get();
}

#include "Test_colectie.h"
