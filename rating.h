#include <string>

class Rating {

	public:

		friend std::ostream& operator<<(std::ostream& os, Rating r) {
			os << "okay rating";
			return os;
		}

};