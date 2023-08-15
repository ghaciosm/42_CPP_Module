#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        materia[i] = NULL; // Materiya listesini başlangıçta boş olarak ayarla
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.materia[i])
        {
            materia[i] = other.materia[i]->clone(); // Materiayı kopyala
        }
        else
        {
            materia[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            delete materia[i];
            if(other.materia[i])
            {
                materia[i] = other.materia[i]->clone();
            }
            else 
            {
                materia[i] = NULL;
            }
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete materia[i]; // Materiayı bellekten temizle
    }
}

void    MateriaSource::learnMateria(AMateria *m)
{
    for(int i = 0; i < 4; i++)
    {
        if(materia[i] == NULL)
        {
            materia[i] = m->clone();
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i= 0; i < 4; i++)
    {
        if(materia[i] && materia[i]->getType() == type)
            return materia[i]->clone();
    }
    return NULL;
}