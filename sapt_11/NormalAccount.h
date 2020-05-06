//
// Created by marius on 06.05.2020.
//

#ifndef PROJ_NORMALACCOUNT_H
#define PROJ_NORMALACCOUNT_H


#include <ostream>
#include "Account.h"

class NormalAccount : public Account {
    std::string status;
public:
    NormalAccount(const char *mail, const char *status);

    NormalAccount(const NormalAccount &other) = default;

    NormalAccount &operator=(const NormalAccount &other) = default;

    void setStatus(const std::string &status);

    void print(std::ostream &os) const override;
};


#endif //PROJ_NORMALACCOUNT_H
