#include <iostream>

int* generateFibonacci(int n) {
	if (n <= 0) return nullptr;
	int* fib = new int[n];
	fib[0] = 1;
	if (n > 1) fib[1] = 1;
	for (int i = 2; i < n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib;
}

int main() {
	int n = 10;
	int* fib = generateFibonacci(n);
	if (fib) {
		std::cout << "Fibonacci sequence: ";
		for (int i = 0; i < n; i++) {
			std::cout << fib[i] << " ";
		}
		std::cout << std::endl;
		delete[] fib;
	}
	return 0;
}