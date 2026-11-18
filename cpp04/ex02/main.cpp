#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	// Animal is abstract now. Uncomment these to see the compile error:
	// Animal	a;
	// Animal	*b = new Animal();

	std::cout << "===== Subject test =====" << std::endl;
	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		delete j;
		delete i;
	}

	std::cout << std::endl << "===== Array: half Dogs, half Cats =====" << std::endl;
	{
		const int	size = 4;
		Animal		*animals[size];

		for (int k = 0; k < size; k++)
		{
			if (k < size / 2)
				animals[k] = new Dog();
			else
				animals[k] = new Cat();
		}
		std::cout << "--- sounds ---" << std::endl;
		for (int k = 0; k < size; k++)
			animals[k]->makeSound();
		std::cout << "--- deleting ---" << std::endl;
		for (int k = 0; k < size; k++)
			delete animals[k];
	}

	std::cout << std::endl << "===== Deep copy: copy constructor =====" << std::endl;
	{
		Dog	original;

		original.getBrain()->setIdea(0, "I want a bone");
		Dog	copy(original);

		copy.getBrain()->setIdea(0, "I want to chase the cat");
		std::cout << "original idea: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "copy idea:     " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "same brain? " << (original.getBrain() == copy.getBrain() ? "yes (BAD)" : "no (good)") << std::endl;
	}

	std::cout << std::endl << "===== Deep copy: assignment =====" << std::endl;
	{
		Cat	a;
		Cat	b;

		a.getBrain()->setIdea(0, "I want fish");
		b = a;
		b.getBrain()->setIdea(0, "I want to sleep");
		std::cout << "a idea: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "b idea: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << "same brain? " << (a.getBrain() == b.getBrain() ? "yes (BAD)" : "no (good)") << std::endl;
	}

	std::cout << std::endl << "===== Copy goes out of scope first =====" << std::endl;
	{
		Dog	basic;

		basic.getBrain()->setIdea(0, "still here");
		{
			Dog	tmp = basic;
		}
		std::cout << "basic idea after tmp died: " << basic.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << std::endl << "===== Out of range ideas =====" << std::endl;
	{
		Cat	cat;

		cat.getBrain()->setIdea(-1, "nope");
		cat.getBrain()->setIdea(100, "nope");
		cat.getBrain()->setIdea(99, "last idea");
		std::cout << "idea[-1]:  \"" << cat.getBrain()->getIdea(-1) << "\"" << std::endl;
		std::cout << "idea[100]: \"" << cat.getBrain()->getIdea(100) << "\"" << std::endl;
		std::cout << "idea[99]:  \"" << cat.getBrain()->getIdea(99) << "\"" << std::endl;
	}
	return (0);
}
