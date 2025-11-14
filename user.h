#include <iostream>
#include <unordered_map>
#include "rating.h"

class User {
protected:
	std::unordered_map<int, Rating> ratings {};
	std::string username;
public:
	User(std::string name) {
		username = name;
		
	}
	User(std::string name, std::unordered_map<int, Rating> ratings) {
		username = name;
		this->ratings = ratings;
	}

	std::unordered_map<int, Rating> get_ratings() {
		return ratings;
	}

	bool has_ratings() {
		return ratings.size() >= 1;
	}

	friend std::ostream& operator<<(std::ostream& os, User& u) {
		os << u.username;
		return os;
	}



	~User() {
		std::cout << "user dead\n";
	}



};