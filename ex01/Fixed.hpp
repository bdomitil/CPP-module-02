#include <iostream>
#include <cmath>
#define small_base 2.7182f

class Fixed
{
private:
	int _fixed_point;
	static const int _fract_bits = 8;
	static const int _smallest_repres;

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
	Fixed operator+ (const Fixed &fixed2);
	Fixed operator- (const Fixed &fixed2);
	Fixed operator/ (const Fixed &fixed2);
	Fixed operator* (const Fixed &fixed2);

	Fixed &operator++ (void); //postfix
	Fixed &operator-- (void); //postfix
	Fixed &operator++ (int); //prefix
	Fixed &operator--(int); //prefix



};

std::ostream &operator<< (std::ostream &stream , const Fixed &fixed);
bool operator> (const Fixed &fixed1, const Fixed &fixed2);
bool operator< (const Fixed &fixed1, const Fixed &fixed2);
bool operator<= (const Fixed &fixed1, const Fixed &fixed2);
bool operator>= (const Fixed &fixed1, const Fixed &fixed2);
bool operator== (const Fixed &fixed1, const Fixed &fixed2);
bool operator!= (const Fixed &fixed1, const Fixed &fixed2);