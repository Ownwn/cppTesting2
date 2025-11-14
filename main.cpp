#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "user.h"
#include "song.h"

std::vector dummy_names = {"frank ocean", "marco", "the pope", "settlers of catan enjoyer"};

std::vector song_names = {"minions", ""}

User create_dummy_user() {
    int index = rand() % dummy_names.size();
    User user(dummy_names[index]);
    return user;
}

int main() {
    User magnus("magnu");
    if (magnus.has_ratings()) {
        std::cout << magnus << " has rating " << magnus.get_ratings().at(0) << '\n';
    } else {
        std::cout << magnus << " has no ratings :(\n";
    }

    std::vector<std::string> v;
    Song song("chungus humungus", 600, v);
    std::cout << song.getRating();

    User dummy = create_dummy_user();
    std::cout << dummy << " is dummy\n";
    
    return 0;
}