//
// Created by marius on 19/03/2020.
//

#include <iostream>
#include <concepts>
#include <olcPixelGameEngine.h>

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
    virtual ~BasicNod() {
        std::cout << "d simplu baza\n";
    };

    int getInfo() const { return info; }

    BasicNod *getPrev() const { return prev; }
    BasicNod *getNext() const { return next; }

    explicit BasicNod(int info = 0) : prev(nullptr), next(nullptr), info{info} {}

    friend std::ostream &operator<<(std::ostream &os, const BasicNod &nod) {
        os << "(" << nod.info << ")";
        return os;
    }

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

template <typename T>
concept Printable = requires(const T& v, std::ostream& os) {
    os << v;
};

template <Printable T>
class abc {
    T x;
public:
    friend std::ostream& operator<<(std::ostream& os, const abc<T>& ob) { os << ob.x; return os; }
};

template <typename T>
concept Playable = requires(T v) {
    { v.play() } -> std::same_as<void>;
};

class instrument {
    std::string nume;
public:
    void play() { std::cout << nume; }
    // int play() { std::cout << nume; return 1; }  // err
};

template <Playable T>
class def {
    T x;
public:
    void f() {
        x.play();
    }
};

int main() {
    //abc<BasicNod> a;
    abc<abc<VNod>> a;
    std::cout << a << "\n---\n";
    def<instrument> d;
    d.f();

    Nod *n = new VNod(3);
    n->f();
    BasicNod n3;
    n3.g();
    BasicNod *n2 = new VBNod(2);
    std::cout << n2->getPrev() << "\n";
    BasicNod *nod_next = n2->getNext();
    if(nod_next != nullptr)
        std::cout << *nod_next << "\n";
    //n2->g();
    delete n;
    delete n2;
    std::cout << "\n\n";
    std::cout << sizeof(Nod) << " " << sizeof(BasicNod) << std::endl;
    ListaDubluInlantuita lista;
    lista.add(1, 0);
    std::cout << lista;
    lista.add(2, 0);
    std::cout << lista;
    lista.remove(1);
//    lista.add(3, 1);
//    std::cout<<lista;
//    lista.add(3, 1);
//    std::cout<<lista;
}
