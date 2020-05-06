//
// Created by marius on 06.05.2020.
//

#include "Repository.h"
#include "repo_full.h"

std::ostream &operator<<(std::ostream &os, const Repository &repository) {
    os << "name: " << repository.name << " commits: [\n";
    for (int i = 0; i < repository.curr_size; ++i) {
        os << "\t" << repository.commits[i] << "\n";
    }
    os << "]\n";
    return os;
}

Repository::Repository(const std::string &name, int max_size) : name(name), max_size(max_size) {
//    const int MAX_SIZE = 100;
    commits = new Commit[max_size];
    curr_size = 0;
    commits[curr_size++] = Commit("Initial commit", 0);
}

void Repository::add_commit(const Commit &commit) {
    if (curr_size < max_size)
        commits[curr_size++] = commit;
    else
        throw repo_full();
}

Repository::~Repository() {
    delete[] commits;
}

Repository::Repository(const Repository &repo) : name(repo.name), curr_size(repo.curr_size), max_size(repo.max_size) {
    commits = new Commit[max_size];
    for (int i = 0; i < curr_size; ++i) {
        commits[i] = repo.commits[i];
    }
}

void Repository::swap(Repository other) {
    using std::swap;
    swap(commits, other.commits);
    swap(name, other.name);
    swap(curr_size, other.curr_size);
    swap(max_size, other.max_size);
}

Repository &Repository::operator=(const Repository &clone) {
    swap(clone);
    return *this;
}
