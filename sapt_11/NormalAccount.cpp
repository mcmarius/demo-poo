//
// Created by marius on 06.05.2020.
//

#include "NormalAccount.h"

NormalAccount::NormalAccount(const char *mail, const char *status) : Account(mail), status(status) {
}

void NormalAccount::print(std::ostream &os) const {
    Account::print(os);
    os << " status: " << status;
}

void NormalAccount::setStatus(const std::string &status) {
    NormalAccount::status = status;
}

//NormalAccount::NormalAccount(const NormalAccount &other) : Account() status(other.status) {
//}

