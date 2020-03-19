//
// Created by marius on 19/03/2020.
//

#include <iostream>
#include "Nod.h"

std::ostream &operator<<(std::ostream &os, const Nod &nod) {
    os << "nod: " << nod.info;
    return os;
}

Nod::Nod(int info) : info{info} {
    prev = next = nullptr;
}

Nod *Nod::getNext() const {
    return next;
}

int Nod::getInfo() const {
    return info;
}

Nod::~Nod() {
    std::cout << "distrus nod cu info " << info << std::endl;
}

