//
// Created by marius on 19/03/2020.
//

#include "ListaDubluInlantuita.h"

std::istream &operator>>(std::istream &is, [[maybe_unused]] ListaDubluInlantuita &lista) {
    return is;
}

std::ostream &operator<<(std::ostream &os, const ListaDubluInlantuita &lista) {
    os << "(";
    for(Nod *nod = lista.first; nod != lista.last; nod = nod->getNext())
        os << nod->getInfo() << ", ";
    os << lista.last->getInfo() << ")\n";
    return os;
}

/**
 * n1 -> ... -> ni-1 -> ni -> ni+1 -> ...
 * @param info
 * @param poz
 */
void ListaDubluInlantuita::add(int info, int poz) {
    Nod *prev_nod, *nod, *new_nod;
    new_nod = new Nod(info);
    if(first == nullptr) {
        first = last = new_nod;
        return;
    }
    if(poz == 0) {
        new_nod->prev = nullptr;
        if(first != last) {
            nod = first->next;
            new_nod->next = nod;
            nod->prev = new_nod;
            first = new_nod;
        }
        else {
            nod = first;
            nod->next = nullptr;
            nod->prev = new_nod;
            new_nod->next = nod;
            first = new_nod;
        }
        return;
    }
    nod = first;
    for(int i = 0; i < poz - 1 && nod->next != nullptr; ++i) {
        nod = nod->next;
    }
    prev_nod = nod;
    nod = nod->next;
    prev_nod->next = new_nod;
    new_nod->prev = prev_nod;
    new_nod->next = nod;
    nod->prev = new_nod;
}

void ListaDubluInlantuita::remove([[maybe_unused]] int poz) {
}

ListaDubluInlantuita operator+([[maybe_unused]] const ListaDubluInlantuita &a, [[maybe_unused]] const ListaDubluInlantuita &b) {
    return ListaDubluInlantuita{};
}

ListaDubluInlantuita::ListaDubluInlantuita() {
    first = last = nullptr;
}

ListaDubluInlantuita::~ListaDubluInlantuita() {
    Nod *prev = first;
    if(first == last) {
//        if(fi)
        delete first;
    }
    else {
        for(Nod *nod = first->next; nod != nullptr; nod = nod->next) {
            delete prev;
            prev = nod;
        }
        delete last;
    }
}
