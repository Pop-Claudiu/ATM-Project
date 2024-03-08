//
// Created by Gabriel on 3/28/2023.
//

#include <iostream>
#include "Colectie.h"

Colectie::Colectie() {
//    capacity = 20;
//    size = 0;
//    elements = new T[capacity];
//    occurences = new int[capacity];
}

Colectie::~Colectie() {
//    delete[] elements; elements = nullptr;
//    delete[] occurences; occurences = nullptr;
}

//void Colectie::resize() {
//    capacity *= 2;
//    T* new_elements; new_elements = new T[capacity];
//    int* new_occurences; new_occurences = new int[capacity];
//    for (int i = 0; i < size; i++) {
//        new_elements[i] = elements[i];
//        new_occurences[i] = occurences[i];
//    }
//    delete[] elements; elements = nullptr;
//    delete[] occurences; occurences = nullptr;
//    elements = new_elements;
//    occurences = new_occurences;
//}

void Colectie::add(TElem elem) {
    int poz = search(elem);
    if(poz >= 0){
        int pairr = elements.search(elements.get_at(poz));
        elements.update(poz, std::make_pair(elem, elements.get_at(poz).second+1));
        //elements[poz].second++;
    }
    else{
        elements.push_back(std::make_pair(elem, 1));
    }
}

bool Colectie::remove(TElem elem) {
    int poz = search(elem);
    if (poz >= 0){
        if(elements.get_at(poz).second > 1){
            elements.update(poz, std::make_pair(elem, elements.get_at(poz).second-1));
            //elements.get_at(poz).second--;
        }
        else{
            elements.delete_at(poz);
        }
        return true;
    }
    return false;
}

int Colectie::search(TElem elem) {
//    for (int i = 0; i < size; i++) {
//        if(elements[i] == elem) return i;
//    }
//    return -1;
    for (int i = 0; i < this->elements.size(); i++) {
        if(elements.get_at(i).first == elem) return i;
    }
    return -1;
}

int Colectie::nroccurrences(TElem elem) {
    for (int i = 0; i < this->elements.size(); i++) {
        if(elements.get_at(i).first == elem) return elements.get_at(i).second;
    }
    return 0;
}

int Colectie::getAt(int position) {
    return elements.get_at(position).first;
}

Colectie& Colectie::operator=(const Colectie &rRight) {
//    this->size = rRight.size;
//    this->capacity = rRight.capacity;
//    for (int i = 0; i < rRight.size_colectie(); i++) {
//        this->elements[i] = rRight.elements[i];
//        this->occurences[i] = rRight.occurences[i];
//    }
    this->elements = rRight.elements;
    return *this;
}

ostream &operator<<(ostream &os, Colectie &col) {
    for (int i = 0; i < col.size_colectie(); i++) {
        if(col.elements.get_at(i).first == 1) cout << "   " << "1 leu x" << col.elements.get_at(i).second << endl;
        else
            cout << "   " << col.elements.get_at(i).first << " lei x" << col.elements.get_at(i).second << endl;
    }
    return os;
}

int Colectie::sum() {
    int suma = 0;
    for (int i = 0; i < elements.size(); i++) {
        suma += elements.get_at(i).second * elements.get_at(i).first;
    }
    return suma;
}

Colectie::Colectie(const Colectie &col) {
//    this->size = col.size;
//    this->capacity = col.capacity;
//    for (int i = 0; i < col.size_colectie(); i++) {
//        this->elements[i] = col.elements[i];
//        this->occurences[i] = col.occurences[i];
//    }
    //this->elements.reserve(col.elements.size());
    for (int i = 0; i < col.elements.size(); i++) {
        this->elements.push_back(col.elements.get_at(i));
    }
}

int Colectie::size_colectie() const {
    return int(elements.size());
}
