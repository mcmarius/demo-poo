//
// Created by marius on 06.05.2020.
//

#ifndef PROJ_CANDIDAT_H
#define PROJ_CANDIDAT_H


#include <string>
#include <ostream>

class Candidat {
    enum TipCandidat {
        IF, ID, A2F
    };
    int nr_inregistrare;
    TipCandidat tip;
    float nota_proba, nota_bac;
    std::string nume;
public:
    std::string cod() {
        switch (tip) {
            case IF:
                return std::to_string(nr_inregistrare);
            case ID:
                return "ID_" + std::to_string(nr_inregistrare);
            case A2F:
                return "ID2_" + std::to_string(nr_inregistrare);
        }
    }

    virtual void print(std::ostream &os) const {
        os << "nr_inregistrare: " << nr_inregistrare << " tip: " << tip << " nota_proba: "
           << nota_proba << " nota_bac: " << nota_bac << " nume: " << nume;
    }

    friend std::ostream &operator<<(std::ostream &os, const Candidat &candidat) {
        candidat.print(os);
        return os;
    }
};

class CandidatRoman : public Candidat {
    std::string serie_CI;
    int nr_CI;
public:
    void print(std::ostream &os) const override;
};

class CandidatStrain : public Candidat {
    int nr_pass;
public:
    void print(std::ostream &os) const override;
    //std::string
};


#endif //PROJ_CANDIDAT_H
