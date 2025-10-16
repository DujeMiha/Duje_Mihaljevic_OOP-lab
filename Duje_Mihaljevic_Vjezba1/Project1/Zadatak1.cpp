#include <iostream>
#include <string>
#include <iomanip>


int main() {
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << "With boolalpha: " << std::boolalpha << flag << std::endl;
	std::cout << "With noboolalpha: " << std::noboolalpha << flag << std::endl;

	int a = 255;
	std::cout << "With uppercase hex: " << std::hex << std::uppercase << a << std::endl;
	std::cout << "With nouppercase hex: " << std::hex << std::nouppercase << a << std::endl;
	std::cout << "Decimal: " << std::dec << a << std::endl;
	std::cout << "Octal: " << std::oct << a << std::endl;

	double pi = 3.141592;
	std::cout << "Scientific (uppercase): " << std::scientific << std::uppercase
		<< std::setprecision(7) << pi << std::endl;
	std::cout << "Fixed (lowercase): " << std::fixed << std::nouppercase
		<< std::setprecision(3) << pi << std::endl;
	std::cout << "Left aligned (setw 20): " << std::left << std::setw(20)
		<< std::setfill('*') << pi << std::endl;
	std::cout << "Right aligned (setw 20): " << std::right << std::setw(20)
		<< std::setfill('#') << pi << std::endl;

	std::cout << "Enter a number with leading spaces: ";
	std::cin >> std::ws; 
	int num;
	std::cin >> num;
	std::cout << "Number: " << num << std::ends;
	std::cout << std::flush << "Flushed output" << std::endl;

	return 0;
}