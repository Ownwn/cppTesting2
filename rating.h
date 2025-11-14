#include <string>

class Rating {
private:
	int value = -1;
	std::string comments = "";

public:
	Rating() {

	}

	Rating(int value) {
		this->value = value;
	}

	Rating(std::string comments, int value) {
		this->value = value;
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