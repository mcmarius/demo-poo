//
// Created by marius on 06.05.2020.
//

#include "Account.h"

Account::Account(const char *mail) : mail(mail) {

}

void Account::print(std::ostream &os) const {
    os << "mail: " << mail << " repos: ";
    for (const auto &repo : repos)
        os << repo;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    account.print(os);
    return os;
}
