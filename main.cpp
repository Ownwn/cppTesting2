#include <iostream>
#include "owen.h"
#include <string>
#include <vector>
#include <unordered_set>
#include "user.h"

int main() {
    std::cout << "Hello, World !" << hey() << std::endl;
    User a(10);
    std::cout << "user has rating " << a.get_ratings().at(0).to_string() << '\n';
    return 0;
}