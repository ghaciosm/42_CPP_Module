#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    value = val << bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << bits));;
    std::cout << "Float constructer called." << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)//nesne kendine atanmasın diye
    {
        value = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(value);
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}
//direkt kaydırmıyoruz değeri bozulur diye
float Fixed::toFloat() const
{
    return((float)(value) / ( 1 << bits));
}

int Fixed::toInt() const
{
    return(value >> bits);
}

/*Amaç, Fixed sınıfının nesnelerini doğrudan çıkış 
akışına (std::cout) yazdırmak için uygun bir işlemciyi tanımlamaktır.*/
std::ostream & operator<<(std::ostream& out, Fixed obj)
{
    out << obj.toFloat();
    return(out);
}