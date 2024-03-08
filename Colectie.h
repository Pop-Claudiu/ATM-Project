//
// Created by Gabriel on 3/28/2023.
//

#ifndef LAB2SD_COLECTIE_H
#define LAB2SD_COLECTIE_H
#include <vector>
#include <iostream>

#include "List.h"

typedef int TElem;
using namespace std;

class Colectie {
private:
    List<std::pair<int, int>> elements;
public:
    Colectie();
    Colectie(const Colectie& col);
    ~Colectie();
    void add(TElem element);
    bool remove(TElem elem);
    int search(TElem elem);
    int size_colectie() const;
    int nroccurrences(TElem elem);
    int getAt(int position);
    Colectie& operator=(const Colectie& rRight);
    friend ostream& operator<<(ostream& os, Colectie& col);
    int sum();
};


#endif //LAB2SD_COLECTIE_H
