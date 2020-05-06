//
// Created by marius on 06.05.2020.
//

#ifndef PROJ_ACCOUNT_H
#define PROJ_ACCOUNT_H


#include <vector>
#include <string>
#include <ostream>
#include "Repository.h"

class Account {
protected:
    std::string mail;
    std::vector<Repository> repos;

    Account(const char *mail);

public:
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    virtual void print(std::ostream &os) const;
};


#endif //PROJ_ACCOUNT_H
