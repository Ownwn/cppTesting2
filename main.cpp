#include <iostream>
#include "owen.h"
#include <string>
#include <vector>
#include <unordered_set>
#include "user.h"

int main() {
    std::cout << "Hello, World !" << hey() << std::endl;
    User magnus("magnu");
    if (magnus.has_ratings()) {
        std::cout << magnus << " has rating " << magnus.get_ratings().at(0) << '\n';
    } else {
        std::cout << magnus << " has no ratings :(\n";
    }
    
    return 0;
}