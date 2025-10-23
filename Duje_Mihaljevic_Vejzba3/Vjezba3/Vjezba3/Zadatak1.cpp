#include <iostream>
#include <cstddef>

inline bool ascending(int a, int b) {
	return a < b;
}

inline bool descending(int a, int b) {
	return a > b;
}

void sortt(int arr[], std::size_t n, bool(*cmp)(int, int)) {
	for (std::size_t i = 0; i < n - 1; ++i) {
		for (std::size_t j = 0; j < n - i - 1; ++j) {
			if (!cmp(arr[j], arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int niz[] = { 5, 2, 9, 1, 7 };
	std::size_t velicina = sizeof(niz) / sizeof(niz[0]);

	std::cout << "Pocetni niz: ";
	for (std::size_t i = 0; i < velicina; ++i)
		std::cout << niz[i] << " ";
	std::cout << "\n";

	sortt(niz, velicina, ascending);
	std::cout << "Uzlazno sortirano: ";
	for (std::size_t i = 0; i < velicina; ++i)
		std::cout << niz[i] << " ";
	std::cout << "\n";

	sortt(niz, velicina, descending);
	std::cout << "Silazno sortirano: ";
	for (std::size_t i = 0; i < velicina; ++i)
		std::cout << niz[i] << " ";
	std::cout << "\n";

	return 0;
}
