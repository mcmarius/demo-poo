//
// Created by marius on 19/03/2020.
//

#ifndef PROJ_LISTADUBLUINLANTUITA_H
#define PROJ_LISTADUBLUINLANTUITA_H

#include <istream>
#include <ostream>
#include "Nod.h"

class ListaDubluInlantuita {
    Nod *first, *last;
public:
    ListaDubluInlantuita();
    virtual ~ListaDubluInlantuita();
    void add(int info, int poz);
    void remove(int poz);
    friend ListaDubluInlantuita operator+(const ListaDubluInlantuita &a, const ListaDubluInlantuita &b);
    friend std::ostream &operator<<(std::ostream &os, const ListaDubluInlantuita &inlantuita);
    friend std::istream &operator>>(std::istream &is, const ListaDubluInlantuita &lista);
};

#endif //PROJ_LISTADUBLUINLANTUITA_H
