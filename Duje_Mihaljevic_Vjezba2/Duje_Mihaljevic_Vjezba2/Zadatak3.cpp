#include <iostream>
#include <iomanip>

double** createMatrix(int m, int n) {
	double** matrix = new double*[m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new double[n];
	}
	return matrix;
}

void deleteMatrix(double** matrix, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void inputMatrix(double** matrix, int m, int n) {
	std::cout << "Enter " << m << "x" << n << " matrix elements:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void generateMatrix(double** matrix, int m, int n, double a, double b) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
		}
	}
}

double** addMatrices(double** a, double** b, int m, int n) {
	double** result = createMatrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
	return result;
}

double** subtractMatrices(double** a, double** b, int m, int n) {
	double** result = createMatrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = a[i][j] - b[i][j];
		}
	}
	return result;
}

double** multiplyMatrices(double** a, int m1, int n1, double** b, int m2, int n2) {
	if (n1 != m2) return nullptr;
	double** result = createMatrix(m1, n2);
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			result[i][j] = 0;
			for (int k = 0; k < n1; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return result;
}

double** transposeMatrix(double** matrix, int m, int n) {
	double** result = createMatrix(n, m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result[j][i] = matrix[i][j];
		}
	}
	return result;
}

void printMatrix(double** matrix, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::right << std::fixed << std::setprecision(4) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int m = 2, n = 3;
	double** mat1 = createMatrix(m, n);
	double** mat2 = createMatrix(m, n);

	inputMatrix(mat1, m, n);
	generateMatrix(mat2, m, n, 0.0, 10.0);

	std::cout << "Matrix 1:\n";
	printMatrix(mat1, m, n);
	std::cout << "Matrix 2:\n";
	printMatrix(mat2, m, n);

	double** sum = addMatrices(mat1, mat2, m, n);
	std::cout << "Sum:\n";
	printMatrix(sum, m, n);
	deleteMatrix(sum, m);

	double** trans = transposeMatrix(mat1, m, n);
	std::cout << "Transpose of Matrix 1:\n";
	printMatrix(trans, n, m);
	deleteMatrix(trans, n);

	deleteMatrix(mat1, m);
	deleteMatrix(mat2, m);

	return 0;
}