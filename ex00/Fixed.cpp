#include "Fixed.hpp"

Fixed &Fixed :: operator= (Fixed &fixed2)
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

Fixed :: ~Fixed()
{
    std::cout << "Destructor has been called" << std::endl;
}

Fixed :: Fixed (Fixed &original)
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