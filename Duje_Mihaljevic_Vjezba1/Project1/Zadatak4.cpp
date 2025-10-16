#include <iostream>

int& at(int* niz, int i) {
	return niz[i];
}

int main() {
	int niz[] = { 1, 2, 3, 4, 5 };

	at(niz, 2) += 1;

	for (int i = 0; i < 5; ++i) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
