//
// Created by marius on 06.05.2020.
//

#ifndef PROJ_REPOSITORY_H
#define PROJ_REPOSITORY_H


#include <string>
#include <ostream>
#include "Commit.h"

class Repository {
    std::string name;
    Commit *commits;
    int curr_size, max_size;
public:
    friend std::ostream &operator<<(std::ostream &os, const Repository &repository);

    explicit Repository(const std::string &name, int max_size = 100);

    Repository(const Repository &clone);

    Repository &operator=(const Repository &clone);

    ~Repository();

    void add_commit(const Commit &commit);

    void swap(Repository other);

};


#endif //PROJ_REPOSITORY_H
