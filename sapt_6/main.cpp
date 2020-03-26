//
// Created by marius on 26/03/2020.
//

#include <iostream>

class Baza {
protected:
    int info;

    void print(const std::string &mesaj) {
        std::cout << mesaj << " " << info << "\n";
    }

public:
    explicit Baza(int info) : info{info} {
        print("c baza");
    }

//    explicit Baza(const std::string& s) : info{0} {print(s);}
    void setInfo(int info) {
        Baza::info = info;
    }

    Baza(const Baza &b) {
        info = b.info;
        print("cc baza");
    }

    virtual void f(int x) {
        std::cout << x;
        print("f()");
    }

    virtual ~Baza() {
        print("d baza");
    }
};

class Derivat : public Baza {
public:
    explicit Derivat(int info = 0) : Baza{info} {
        print("c der");
    }

    void f(int x) override {
//        Baza::f(x);
        print("f() der");
    }

    ~Derivat() override {
        print("d der");
    }
};

class BazaSimplu {
protected:
    int info;

    void print(const std::string &mesaj) {
        std::cout << mesaj << " " << info << "\n";
    }

public:
    BazaSimplu(const BazaSimplu &b) : info(b.info) {
        print("cc b simplu");
    }

    void setInfo(int info) {
        BazaSimplu::info = info;
    }

    explicit BazaSimplu(int info = 0) : info{info} {
        print("c b simplu");
    }

    ~BazaSimplu() {
        print("d b simplu");
    }
};

class DerivatSimplu : public BazaSimplu {
public:
    explicit DerivatSimplu(int info = 0) : BazaSimplu(info) {
        print("c der simplu");
    }

    ~DerivatSimplu() {
        print("d der simplu");
    }
};

void f(Baza b) {
    b.f(1);
}

int main() {
//    DerivatSimplu ds;
//    Derivat d;
//    std::string s("??");
//    f(1);
//    f(s);
//    Baza b1(4);
//    f(b1);
//    Derivat d1;

    /*Derivat d(1);
    DerivatSimplu ds(2);
    Baza *b = new Derivat(1);
    b->f(10);
    delete(b);
    BazaSimplu *bs = new DerivatSimplu(2);
    delete(bs);
    std::cout<<sizeof(Baza)<<" "<< sizeof(BazaSimplu);*/

    /*Baza b1 = Derivat(3);
    b1.f(5);
    BazaSimplu bs1 = DerivatSimplu(4);*/

    void testInitial();

    return 0;
}
