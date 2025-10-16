#include <iostream>

int ograniči(int vrijednost, int low = 0, int high = 100) {
	if (vrijednost < low) return low;
	if (vrijednost > high) return high;
	return vrijednost;
}

double ograniči(double vrijednost, double low = 0.0, double high = 100.0) {
	if (vrijednost < low) return low;
	if (vrijednost > high) return high;
	return vrijednost;
}

int main() {
	std::cout << "Int: " << ograniči(150) << std::endl;
	std::cout << "Double: " << ograniči(-5.5) << std::endl;
	return 0;
}
