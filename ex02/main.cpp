#include "Fixed.hpp"

int main()
{
    Fixed	a;
	Fixed	b( 10 );
	Fixed 	c( 2.0f);
	Fixed	d( b );

	a = Fixed( 1234.4321f );
	

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;


	std::cout << "a is " << a++ << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "biggest is " << Fixed :: max(b, c) << std::endl;
	std::cout << "result of 10 / 2 = " << b / c << std::endl;

	return 0;
}