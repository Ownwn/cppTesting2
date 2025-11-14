#include <string>

class Rating {
private:
	int value = -1;

public:
	Rating() {

	}

	Rating(int value) {
		this->value = value;
	}

	friend std::ostream& operator<<(std::ostream& os, Rating& r) {
		if (r.value == -1) {
			os << "No rating!";
		} else {
			os << r.value;
		}
		
		return os;
	}

};