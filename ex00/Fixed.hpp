#include <iostream>

class Fixed
{
private:
	int _fixed_point;
	static const int _fract_bits = 8;
public:
	Fixed();
	Fixed(Fixed &origin);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
	Fixed &operator= (Fixed &fixed2);
};