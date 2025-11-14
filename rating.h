#include <string>

class Rating {
private:
	int max;
	int min;
	int value;

public:

	Rating(int max, int min, int value) {
		this->max = max;
		this->min = min;
		this->value = value;
	}

	friend std::ostream& operator<<(std::ostream& os, Rating& r) {
		os << r.value;
		return os;
	}

};