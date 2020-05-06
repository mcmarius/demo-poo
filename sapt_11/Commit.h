//
// Created by marius on 06.05.2020.
//

#ifndef PROJ_COMMIT_H
#define PROJ_COMMIT_H


#include <string>
#include <ostream>

class Commit {
    std::string message;
    int changes;
public:
    Commit(const std::string &message, int changes);

    Commit(const Commit &c) = default;

    Commit &operator=(const Commit &c) = default;

    ~Commit();

    friend std::ostream &operator<<(std::ostream &os, const Commit &commit);

    Commit();
};


#endif //PROJ_COMMIT_H
