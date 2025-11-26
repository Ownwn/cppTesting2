#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>

#include "media.h"
#include "rating.h"

class User {
protected:
	std::vector<Rating> ratings;
	std::string_view username;
	std::string_view password;
public:
	User(const std::string_view name) {
		username = name;
		
	}
	User(const std::string_view name, std::string_view passwrd){
		username = name;
		password = passwrd;
	}

	std::string_view get_name() const {
		return username;
	}

	std::string_view get_password() const {
		return password;
	}
	User(const std::string_view name, const std::vector<Rating> &ratings) {
		username = name;
		this->ratings = ratings;
	}

	[[nodiscard]] constexpr const std::vector<Rating>& get_ratings() const noexcept {
		return ratings;
	}

	double average_rating() const {
		if (ratings.size() == 0) {
			return 0;
		}
		double res = 0;
		for (auto& rating : ratings) {
			res+= rating.getValue();
		}
		return res / ratings.size();

	}

	void add_rating(const Rating &r) {
		ratings.push_back(r);
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