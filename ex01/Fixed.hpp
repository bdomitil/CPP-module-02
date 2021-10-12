#include <iostream>
#include <cmath>

class Fixed
{
private:

	int _fixed_point;
	static const int _fract_bits = 8;

public:

	Fixed();
	Fixed(float input);
	Fixed(int input);
	Fixed(const Fixed &origin);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;
	Fixed &operator= (const Fixed &fixed2);
};

std::ostream &operator<< (std::ostream &stream , const Fixed &fixed);