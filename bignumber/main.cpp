#include "bignumber.h"
#include <iostream>

int main()
{
	bignumber mybignumber("-123456789123456789123456789");
	bignumber another("111111111");
	bignumber ResultNumber;
	mybignumber.Show();
	another.Show();
	std::cout << mybignumber.GetLength() << std::endl;
	char *printer = mybignumber.GetNumberString();
	std::cout << "mybignumber.GetNumberString() : " << printer << std::endl;
	std::cout << mybignumber[6] << std::endl;
	ResultNumber = mybignumber * another;
	std::cout << "add Result : ";
	ResultNumber.Show();
	//std::cout << std::endl << ResultNumber.GetLength();
	std::cin.get();
}