//
// Created by marius on 19/03/2020.
//

#include <iostream>
#include "ListaDubluInlantuita.h"

class VNod : public Nod {
public:
    VNod(int info = 0) : Nod(info) {}

    void f() {
        std::cout << "derivat f\n";
    }

    virtual ~VNod() {
        std::cout << "dv derivat\n";
    }
};

class BasicNod {
    BasicNod *prev, *next;
    int info;
public:
    ~BasicNod() {
        std::cout << "d simplu baza\n";
    };

    int getInfo() const { return info; }

    BasicNod *getNext() const { return next; }

    explicit BasicNod(int info = 0) : info{info} {}

    friend std::ostream &operator<<(std::ostream &os, const BasicNod &nod) { return os; }

    void g() {
        std::cout << "baza g\n";
    }
//    friend class ListaDubluInlantuita;
};

class VBNod : public BasicNod {
public:
    VBNod(int info = 0) : BasicNod(info) {};

    virtual ~VBNod() {
        std::cout << "d simplu derivat\n";
    }

    void g() {
        std::cout << "derivat g\n";
    }
};

int main() {
//    Nod *n = new VNod(3);
//    n->f();
//    BasicNod *n2 = new VBNod(2);
//    n2->g();
//    delete n;
//    delete n2;
//    std::cout << "\n\n";
//    std::cout << sizeof(Nod) << " " << sizeof(BasicNod) << std::endl;
//    ListaDubluInlantuita lista;
//    lista.add(1, 0);
//    std::cout << lista;
//    lista.add(2, 0);
//    std::cout << lista;
//    lista.add(3, 1);
//    std::cout<<lista;
//    lista.add(3, 1);
//    std::cout<<lista;
}
