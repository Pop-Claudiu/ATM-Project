//
// Created by Gabriel on 5/2/2023.
//

#include "VectorDinamic.h"
#include <iostream>

VectorDinamic::VectorDinamic(int capacitate) {
    if(capacitate <= 0)
        throw std::invalid_argument("capacitatea trebuie sa fie un numar pozitiv");
    this->capacity = capacitate;
    this->elems = new TElem [capacitate];
    this->nrElems = 0;
}

int VectorDinamic::size() const {
    return this->nrElems;
}

TElem VectorDinamic::getAt(int i) const {
    if(i < 0 || i >= nrElems)
        throw std::invalid_argument("pozitie invalida");
    return this->elems[i];
}

TElem VectorDinamic::update(int i, TElem e) {
    TElem elem = elems[i];
    elems[i] = e;
    return elem;
}

void VectorDinamic::push_back(TElem e) {
    if (nrElems == capacity)
        resize();
    this->elems[nrElems] = e;
    this->nrElems ++;
}

void VectorDinamic::addAt(int i, TElem e) {
    if(i >= 0 and i <= size())
        elems[i] = e;
}

TElem VectorDinamic::sterge(int i) {
    if(i >= 0 and i <= size())
        for (int j = i; j < size() - 1; j++) {
            elems[j] = elems[j + 1];
        }

}

VectorDinamic::~VectorDinamic() {
    delete[] elems; elems = nullptr;
}

void VectorDinamic::resize() {
    capacity *= 2;
    TElem* newElems = new TElem[capacity];
    for (int i = 0; i < size(); i++) {
        newElems[i] = elems[i];
    }
    delete[] elems;
    elems = newElems;
}

































void func() {
    VectorDinamic vector(20);
    vector.sterge(1);
    vector.addAt(1,std::make_pair(1,1));
    vector.push_back(std::make_pair(1,1));
    TElem e = vector.update(1, std::make_pair(1,1));
    e = vector.getAt(2);
}