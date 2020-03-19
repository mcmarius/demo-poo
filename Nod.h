//
// Created by marius on 19/03/2020.
//

#ifndef DEMO_POO2_NOD_H
#define DEMO_POO2_NOD_H

#include <iostream>

class Nod {
    Nod *prev, *next;
    int info;
public:
    virtual ~Nod();
    int getInfo() const;
    Nod *getNext() const;
    explicit Nod(int info);
    friend std::ostream &operator<<(std::ostream &os, const Nod &nod);
    friend class ListaDubluInlantuita;

    void f() {
        std::cout << "baza f\n";
    }
};

#endif //DEMO_POO2_NOD_H
