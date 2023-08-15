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

        bool    operator>(const Fixed &obj) const;
        bool    operator<(const Fixed &obj) const;
        bool    operator>=(const Fixed &obj) const;
        bool    operator<=(const Fixed &obj) const;
        bool    operator==(const Fixed &obj) const;
        bool    operator!=(const Fixed &obj) const;

        Fixed   operator+(const Fixed &obj) const;
        Fixed   operator-(const Fixed &obj) const;
        Fixed   operator*(const Fixed &obj) const;
        Fixed   operator/(const Fixed &obj) const;
        
        Fixed   &operator++();//pre-increment
        Fixed   &operator--();
        //int olmasının nedeni pre ile ayırt etmek genelde kullanilmaz.
        Fixed   operator++(int);//post-increment
        Fixed   operator--(int);

        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream & operator<<(std::ostream& out, Fixed obj);

#endif