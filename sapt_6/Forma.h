//
// Created by marius on 26/03/2020.
//

#ifndef PROJ_FORMA_H
#define PROJ_FORMA_H

class Forma {
    double inaltime;
public:

    virtual ~Forma();
    virtual double arieTotala() = 0;
    virtual double volum() = 0;
};

#endif //PROJ_FORMA_H
