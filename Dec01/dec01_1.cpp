#include <fstream>
#include <sstream>
#include <iostream>

int main() {
	std::ifstream file("input");
	int dial = 50;
	int password = 0;
	if (file.good()) {
		std::string rotation;
		while (getline(file, rotation)) {
			std::string direction = rotation.substr(0, 1);
			int rotate = "R" == direction ? 1 : -1;
			int cipher = (std::stoi(rotation.substr(1)) % 100) * rotate;
			dial = dial + cipher < 0 ? dial + cipher + 100 : dial + cipher > 100 ? dial + cipher - 100 : (dial + cipher) % 100;
			if (0 == dial) {
				password++;
			}
		}
		std::cout << password << "\n";
	}
	return 0;
}
