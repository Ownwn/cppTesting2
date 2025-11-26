#pragma once
#include <string>

#include "media.h"

class Media;

class Rating {
private:
	int value = -1;
	std::string comments = "";
	std::shared_ptr<Media> media;

public:

	int getValue() const {
		return value;
	}

	const std::shared_ptr<Media>& getMedia() const {
		return media;
	}

	Rating(const int& value, const std::shared_ptr<Media> &m) {
		this->value = value;
		this->media = m;
	}

	Rating(const std::string &comments, const int& value, const std::shared_ptr<Media> &m) {
		this->value = value;
		this->media = m;
		this->comments = comments;
	}

	friend std::ostream& operator<<(std::ostream& os, const Rating& r) {
		if (r.value == -1) {
			os << "No rating!\n";
		} else {
			os << r.value << " " << r.comments << '\n';
		}
		
		return os;
	}

};