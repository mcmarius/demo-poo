//
// Created by marius on 26/03/2020.
//

#ifndef PROJ_DREPTUNGHI_H
#define PROJ_DREPTUNGHI_H

#include "Forma.h"

class Dreptunghi : public Forma {
public:
    Dreptunghi(double d);
    double arieTotala() override;
    double volum() override;
};

#endif //PROJ_DREPTUNGHI_H
