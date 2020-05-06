//
// Created by marius on 06.05.2020.
//


#include <iostream>
#include "Account.h"
#include "NormalAccount.h"
#include "repo_full.h"

int main() {

    NormalAccount account = NormalAccount("a@test.com", "student @ fmi unibuc");
    std::cout << account << "\n";
    NormalAccount other_account(account);
    account.setStatus("schimbat");
    std::cout << account << "\n" << other_account << "\n";
    account = other_account;
    std::cout << account << "\n" << other_account << "\n";
    Repository repo("test", 10);
    std::cout << repo;
    repo.add_commit(Commit("Add changes", 3));
    std::cout << repo;
    try {
        repo.add_commit(Commit("Add changes", 3));
    }
    catch (repo_full &ex) {
        std::cout << "nu merge insert";
    }
    Repository cloned_repo(repo);
    cloned_repo.add_commit(Commit("Cloned", 1));
    std::cout << cloned_repo << "\n" << repo;
    Repository forked("fork");
    cloned_repo = forked;
    std::cout << cloned_repo << "\n" << forked;
    return 0;
}

