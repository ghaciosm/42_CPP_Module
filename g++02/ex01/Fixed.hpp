#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class  Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed &operator =(const Fixed &other);
        ~Fixed();
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream& out, Fixed obj);

#endif