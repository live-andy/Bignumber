#include "bignumber.h"
#include <iostream>

int main()
{
	bignumber mybignumber("35687888");
	bignumber another("-112");
	bignumber ResultNumber;
	mybignumber.Show();
	another.Show();
	std::cout << mybignumber.GetLength() << std::endl;
	char *printer = mybignumber.GetNumberString();
	std::cout << "mybignumber.GetNumberString() : " << printer << std::endl;
	std::cout << mybignumber[6] << std::endl;
	ResultNumber = mybignumber + another;
	std::cout << "add Result : ";
	ResultNumber.Show();
	std::cin.get();
}