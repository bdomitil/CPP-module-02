#include "Fixed.hpp"

Fixed &Fixed :: operator= (const Fixed &fixed2)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &fixed2)
        this->_fixed_point =  fixed2.getRawBits();
    return (*this);
}

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
    std::cout << "setRawBits has been called" << std::endl;
    _fixed_point = raw << _fract_bits;
}

int Fixed :: getRawBits(void) const
{
    std::cout << "getRawBits has been called" << std::endl;
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