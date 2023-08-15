#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type) 
{
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.getType();
    }
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return(type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
