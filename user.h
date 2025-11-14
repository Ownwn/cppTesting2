#include <iostream>
#include <unordered_map>
#include "rating.h"

class User {
protected:
	std::unordered_map<int, Rating> ratings {};
public:
	User(int i) {
		Rating r;
		ratings.insert({0, r});
	}

	std::unordered_map<int, Rating> get_ratings() {
		return ratings;
	}

	~User() {
		std::cout << "user dead\n";
	}



};