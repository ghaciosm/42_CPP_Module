#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class   MateriaSource : public IMateriaSource
{   
    private:
        AMateria *materia[4]; // öğrenilenlerin saklandığı dizi
    public:
        MateriaSource();
        MateriaSource(const MateriaSource & other);
        MateriaSource &operator=(const MateriaSource & other);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif