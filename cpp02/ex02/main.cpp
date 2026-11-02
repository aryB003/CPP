#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << "--- extra tests ---" << std::endl;
	Fixed	x(10);
	Fixed	y(2.5f);

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x + y = " << x + y << std::endl;
	std::cout << "x - y = " << x - y << std::endl;
	std::cout << "x * y = " << x * y << std::endl;
	std::cout << "x / y = " << x / y << std::endl;
	std::cout << "-x * y = " << Fixed(-10) * y << std::endl;
	std::cout << "x / 0 = ";
	Fixed	divZero = x / Fixed(0);
	std::cout << divZero << std::endl;

	std::cout << std::boolalpha;
	std::cout << "x > y: " << (x > y) << ", x < y: " << (x < y) << std::endl;
	std::cout << "x >= x: " << (x >= x) << ", x <= y: " << (x <= y) << std::endl;
	std::cout << "x == 10: " << (x == Fixed(10)) << ", x != y: " << (x != y) << std::endl;

	std::cout << "--x = " << --x << std::endl;
	std::cout << "x-- = " << x-- << std::endl;
	std::cout << "x   = " << x << std::endl;
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;
	return (0);
}
