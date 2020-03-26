//
// Created by marius on 26/03/2020.
//

#ifndef PROJ_CERC_H
#define PROJ_CERC_H

#include "Forma.h"

class Cerc : public Forma {
public:
    Cerc(double d);
    double arieTotala() override;
    double volum() override;
};

#endif //PROJ_CERC_H
