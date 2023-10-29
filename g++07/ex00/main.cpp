#include "whatever.hpp"
#include <iostream>


//'::' scope resolution operator
int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}




/*int main()
{
    int int1 = 12, int2 = 3;
    char char1 = 'x', char2 = '2';
    std::string str1 = "ali", str2 = "ayse";

    std::cout << std::endl;
    std::cout << "min: " << min(int1, int2) << std::endl;
    std::cout << "max: " << max(int1, int2) << std::endl;
    std::cout <<"before swap: "<< int1 << " - " << int2 << std::endl;
    std::cout << "after swap: ";
    swap(int1, int2);
    std::cout << int1 << " - " << int2 << std::endl;

    std::cout << std::endl;
    std::cout << "min: " << min(char1, char2) << std::endl;
    std::cout << "max: " << max(char1, char2) << std::endl;
    std::cout <<"before swap: "<< char1 << " - " << char2 << std::endl;
    std::cout << "after swap: ";
    swap(char1, char2);
    std::cout << char1 << " - " << char2 << std::endl;

    std::cout << std::endl;
    std::cout << "min: " << min(str1, str2) << std::endl;
    std::cout << "max: " << max(str1, str2) << std::endl;
    std::cout <<"before swap: "<< str1 << " - " << str2 << std::endl;
    std::cout << "after swap: ";
    swap(str1, str2);
    std::cout << str1 << " - " << str2 << std::endl;
}*/