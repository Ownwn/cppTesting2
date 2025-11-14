#include <string>

class Rating {

	public:
		std::string to_string() {
			return "meh";
		}

		friend std::ostream& operator<<(std::ostream& os, Rating r) {
			os << "okay rating";
			return os;
		}

};