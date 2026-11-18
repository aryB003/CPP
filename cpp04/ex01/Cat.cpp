#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	if (this != &other)
		*_brain = *other._brain;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
