//
// Created by marius on 26/03/2020.
//

#include <vector>
#include <iostream>
#include "test_initial.h"
#include "Forma.h"
#include "Cerc.h"
#include "Dreptunghi.h"

enum tip_forma {
    CERC, DREPTUNGHI, PATRAT, TRIUNGHI
};

void test_initial() {
    int nr_forme = 10, tip_baza;
    tip_forma tip;
    double inaltime;
//    Dreptunghi dreptunghi = Dreptunghi(43);
//    Forma &f = dreptunghi;
    std::vector <Forma *> forme;
    for(int i = 0; i < nr_forme; ++i) {
        std::cin >> tip_baza
                 >> inaltime;
        tip = static_cast<tip_forma>(tip_baza);
        switch(tip) {
            case CERC:
                forme.push_back(new Cerc(inaltime));
                break;
            case DREPTUNGHI:
                forme.push_back(new Dreptunghi(inaltime));
                break;
            case PATRAT:
                break;
            case TRIUNGHI:
                break;
        }
    }
    double volum = 0, arieTotala = 0;
    for(int i = 0; i < nr_forme; ++i) {
        volum += forme[i]->volum();
        arieTotala += forme[i]->arieTotala();
    }
}
