#include <iostream>
#include <cstddef>

template <typename T>
void sortt(T arr[], std::size_t n, bool(*cmp)(T, T)) {
	for (std::size_t i = 0; i < n - 1; ++i) {
		for (std::size_t j = 0; j < n - i - 1; ++j) {
			if (!cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
inline bool ascending(T a, T b) {
	return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
	return a > b;
}

int main() {
	int nizInt[] = { 5, 2, 9, 1, 7 };
	double nizDouble[] = { 3.2, 1.5, 4.8, 2.0, 0.9 };
	std::size_t nInt = sizeof(nizInt) / sizeof(nizInt[0]);
	std::size_t nDouble = sizeof(nizDouble) / sizeof(nizDouble[0]);

	std::cout << "Uzlazno sortirani int niz: ";
	sortt(nizInt, nInt, ascending<int>);
	for (std::size_t i = 0; i < nInt; ++i)
		std::cout << nizInt[i] << " ";
	std::cout << "\n";

	std::cout << "Silazno sortirani int niz: ";
	sortt(nizInt, nInt, descending<int>);
	for (std::size_t i = 0; i < nInt; ++i)
		std::cout << nizInt[i] << " ";
	std::cout << "\n";

	std::cout << "Uzlazno sortirani double niz: ";
	sortt(nizDouble, nDouble, ascending<double>);
	for (std::size_t i = 0; i < nDouble; ++i)
		std::cout << nizDouble[i] << " ";
	std::cout << "\n";

	std::cout << "Silazno sortirani double niz: ";
	sortt(nizDouble, nDouble, descending<double>);
	for (std::size_t i = 0; i < nDouble; ++i)
		std::cout << nizDouble[i] << " ";
	std::cout << "\n";

	return 0;
}
