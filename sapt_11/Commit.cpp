//
// Created by marius on 06.05.2020.
//

#include "Commit.h"

Commit::Commit(const std::string &message, int changes) : message(message), changes(changes) {}

std::ostream &operator<<(std::ostream &os, const Commit &commit) {
    os << "message: " << commit.message << " changes: " << commit.changes;
    return os;
}

Commit::Commit() {

}

Commit::~Commit() = default;
