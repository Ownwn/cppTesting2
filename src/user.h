#pragma once
#include <iostream>
#include <unordered_map>
#include "rating.h"

class User {
protected:
	std::unordered_map<int, Rating> ratings {};
	std::string_view username;
public:
	User(const std::string_view name) {
		username = name;
		
	}

	std::string_view get_name() const {
		return username;
	}
	User(const std::string_view name, std::unordered_map<int, Rating> ratings) {
		username = name;
		this->ratings = ratings;
	}

	std::unordered_map<int, Rating> get_ratings() const {
		return ratings;
	}

	double average_rating() const {
		if (ratings.size() == 0) {
			throw std::invalid_argument("ratings is empty! cant calc avg");
		}
		double res = 0;
		for (auto r : ratings) {
			res+= r.second.getValue();
		}
		return res / ratings.size();

	}

	void add_rating(const int &i, const Rating &r) {
		if (ratings.contains(i)) {
			throw std::invalid_argument("rating already exists!");
		}
		ratings[i] = r;
	}

	bool has_ratings() const {
		return ratings.size() >= 1;
	}

	friend std::ostream& operator<<(std::ostream& os, User& u) {
		os << u.username;
		return os;
	}



	~User() {
		// std::cout << "user dead\n";
	}



};