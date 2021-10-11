#include "Fixed.hpp"

int getSmallest(void)
{
    int a =  static_cast<int>(small_base);
     while (a >> 1 < 0)
    {
        if (a >> 2 < 0)
            break;
        a = a >> 1;
    }
    return (a);
}

const int Fixed :: _smallest_repres = getSmallest();

Fixed :: Fixed()
{
    std::cout << "Default constructor has been called" << std::endl;
    this->_fixed_point = 0;
}

Fixed :: Fixed (float input)
{
    std::cout << "float constructor has been called" << std::endl;
    this->_fixed_point =  roundf(input * (1 << _fract_bits));
}

Fixed :: Fixed (int input)
{
    std::cout << "int constructor has been called" << std::endl;
    this->_fixed_point =  roundf(input * (1 << _fract_bits));
}

Fixed :: ~Fixed()
{
    std::cout << "Destructor has been called" << std::endl;
}

Fixed :: Fixed (const Fixed &original)
{
    std::cout << "Copy constructor has been called" << std::endl;
    *this = original;  
}

void Fixed :: setRawBits(int raw)
{
    _fixed_point = raw << _fract_bits;
}

int Fixed :: getRawBits(void) const
{
    return (_fixed_point);
}

int Fixed:: toInt() const
{
    return(_fixed_point >> _fract_bits);
}

float Fixed :: toFloat() const 
{
    return static_cast<float> (_fixed_point) / (1 << _fract_bits) ;
}

std::ostream &operator<< (std::ostream &stream , Fixed const &fixed)
{
    stream << fixed.toFloat();
    return (stream);
}

Fixed &Fixed :: operator= (const Fixed &fixed2)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &fixed2)
        this->_fixed_point =  fixed2.getRawBits();
    return (*this);
}

bool operator==(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.getRawBits() == fixed2.getRawBits())
        return (true);
    return (false);
}

bool operator!=(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.getRawBits() != fixed2.getRawBits())
        return (true);
    return (false);
}

bool operator> (const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.getRawBits() > fixed2.getRawBits())
        return (true);
    return (false);
}

bool operator< (const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.getRawBits() < fixed2.getRawBits())
        return (true);
    return (false);
}

bool operator<= (const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.getRawBits() <= fixed2.getRawBits())
        return (true);
    return (false);
}

bool operator>= (const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.getRawBits() >= fixed2.getRawBits())
        return (true);
    return (false);
}

Fixed  Fixed :: operator+ (const Fixed &fixed2)
{
    Fixed new_obj(this->toFloat() + fixed2.toFloat());
    return (new_obj);
}

Fixed Fixed :: operator- (const Fixed &fixed2)
{
    Fixed new_obj(this->toFloat() - fixed2.toFloat());
    return (new_obj);
}

Fixed Fixed :: operator* (const Fixed &fixed2)
{
    Fixed new_obj(this->toFloat() * fixed2.toFloat());
    return (new_obj);
}

Fixed Fixed :: operator/ (const Fixed &fixed2)
{
    Fixed new_obj(this->toFloat() / fixed2.toFloat());
    return (new_obj);
}

Fixed &Fixed :: operator++ (void) 
{
    this->_fixed_point += _smallest_repres;
    return (*this);
}

Fixed &Fixed :: operator-- (void) 
{
    this->_fixed_point += _smallest_repres;
    return (*this);
}

Fixed &Fixed :: operator++ (int) //prefix
{
    Fixed tmp(this->toFloat());
    this->_fixed_point += _smallest_repres;
    return (tmp);
}

Fixed &Fixed :: operator-- (int) //prefix
{
    Fixed tmp(this->toFloat());
    this->_fixed_point -= _smallest_repres;
    return (tmp);
}