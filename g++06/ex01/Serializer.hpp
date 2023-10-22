#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer const & other);
        Serializer &operator=(const Serializer &other);

        static uintptr_t serialize(Data *ptr);
        static Data * deserialize(uintptr_t raw);
};

#endif