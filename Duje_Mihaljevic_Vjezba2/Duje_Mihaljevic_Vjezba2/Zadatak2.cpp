#include <iostream>

struct Vector {
	int* data;
	int logicalSize;
	int physicalSize;
};

Vector* vector_new(int init) {
	Vector* v = new Vector;
	v->data = new int[init];
	v->logicalSize = 0;
	v->physicalSize = init;
	return v;
}

void vector_delete(Vector* v) {
	delete[] v->data;
	delete v;
}

void vector_push_back(Vector* v, int element) {
	if (v->logicalSize >= v->physicalSize) {

		int* newData = new int[v->physicalSize * 2];
		for (int i = 0; i < v->logicalSize; i++) {
			newData[i] = v->data[i];
		}
		delete[] v->data;
		v->data = newData;
		v->physicalSize *= 2;
	}
	v->data[v->logicalSize++] = element;
}

void vector_pop_back(Vector* v) {
	if (v->logicalSize > 0) {
		v->logicalSize--;
	}
}

int vector_front(const Vector* v) {
	if (v->logicalSize > 0) return v->data[0];
	return 0; 
}

int vector_back(const Vector* v) {
	if (v->logicalSize > 0) return v->data[v->logicalSize - 1];
	return 0;
}

int vector_size(const Vector* v) {
	return v->logicalSize;
}

int main() {
	Vector* v = vector_new(2);
	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);

	std::cout << "Size: " << vector_size(v) << std::endl;
	std::cout << "Front: " << vector_front(v) << std::endl;
	std::cout << "Back: " << vector_back(v) << std::endl;

	vector_delete(v);
	return 0;
}