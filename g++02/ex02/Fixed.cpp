#include "Fixed.hpp"

Fixed::Fixed() : value(0){}
Fixed::Fixed(const int val) : value(val<<bits){}
Fixed::Fixed(const float value) : value(roundf(value * (1 << bits))){}
Fixed::Fixed(const Fixed &other): value(other.value){}
Fixed& Fixed::operator=(const Fixed &other)
{
    if(this != &other)//nesne kendine atanmasın diye
    {
        value = other.value;
    }
    return (*this);
}
Fixed::~Fixed(){}
int     Fixed::getRawBits( void ) const
{
    return(value);
}
void    Fixed::setRawBits( int const raw )
{
    value = raw;
}
float Fixed::toFloat() const
{
    return((float)(value) / ( 1 << bits));
}
int Fixed::toInt() const
{
    return(value >> bits);
}
std::ostream & operator<<(std::ostream& out, Fixed obj)
{
    out << obj.toFloat();
    return(out);
}

//*********************************************

//burdan itibaren
bool Fixed::operator>(const Fixed &obj) const
{
    return(value > obj.value);
}

bool Fixed::operator<(const Fixed &obj) const
{
    return(value < obj.value);
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return(value >= obj.value);
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return(value <= obj.value);
}

bool Fixed::operator==(const Fixed &obj) const
{
    return(value == obj.value);
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return(value != obj.value);
}

Fixed   Fixed::operator+(const Fixed &obj) const
{
    return(toFloat() + obj.toFloat());
}

Fixed   Fixed::operator-(const Fixed &obj) const
{
    return(toFloat() - obj.toFloat());
}

Fixed   Fixed::operator*(const Fixed &obj) const
{
    return(toFloat() * obj.toFloat());
}

Fixed   Fixed::operator/(const Fixed &obj) const
{
    return(toFloat() / obj.toFloat());
}

Fixed   &Fixed::operator++()//nesnenin kendisini döndürüyor
{
    ++value;
    return(*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;
    tmp.value = this->value++;
    return(tmp);
}

Fixed   &Fixed::operator--()
{
    --value;
    return(*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    tmp.value = this->value--;
    return(tmp);
}

const   Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a < b)
        return(a);
    else 
        return(b);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if(a < b)
        return(a);
    else
        return(b);
}

const   Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a > b)
        return(a);
    else 
        return(b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return(a);
    else
        return(b);
}