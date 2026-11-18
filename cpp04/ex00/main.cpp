#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "===== Subject test =====" << std::endl;
	{
		const Animal	*meta = new Animal();
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl << "===== Wrong version: no virtual on makeSound =====" << std::endl;
	{
		const WrongAnimal	*meta = new WrongAnimal();
		const WrongAnimal	*i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}

	std::cout << std::endl << "===== WrongCat called directly (not through a pointer) =====" << std::endl;
	{
		WrongCat	cat;

		cat.makeSound();
	}

	std::cout << std::endl << "===== Array of Animal pointers =====" << std::endl;
	{
		const Animal	*zoo[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

		for (int k = 0; k < 4; k++)
		{
			std::cout << zoo[k]->getType() << " says: ";
			zoo[k]->makeSound();
		}
		for (int k = 0; k < 4; k++)
			delete zoo[k];
	}

	std::cout << std::endl << "===== Dog copy + assignment =====" << std::endl;
	{
		Dog	dog;
		Dog	copy(dog);
		Dog	assigned;

		assigned = dog;
		std::cout << copy.getType() << " / " << assigned.getType() << std::endl;
		copy.makeSound();
		assigned.makeSound();
	}

	std::cout << std::endl << "===== Cat copy + assignment =====" << std::endl;
	{
		Cat	cat;
		Cat	copy(cat);
		Cat	assigned;

		assigned = cat;
		std::cout << copy.getType() << " / " << assigned.getType() << std::endl;
		copy.makeSound();
		assigned.makeSound();
	}

	std::cout << std::endl << "===== WrongCat copy + assignment =====" << std::endl;
	{
		WrongCat	cat;
		WrongCat	copy(cat);
		WrongCat	assigned;

		assigned = cat;
		std::cout << copy.getType() << " / " << assigned.getType() << std::endl;
		copy.makeSound();
		assigned.makeSound();
	}
	return (0);
}
