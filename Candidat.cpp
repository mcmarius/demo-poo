//
// Created by marius on 06.05.2020.
//

#include "Candidat.h"

void CandidatRoman::print(std::ostream &os) const {
    Candidat::print(os);
    os << nr_CI << " " << serie_CI;
}

void CandidatStrain::print(std::ostream &os) const {
    Candidat::print(os);
    os << nr_pass << std::endl;
}
