#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- construction (OCF) ---" << std::endl;
	ClapTrap	clap("Clappy");
	ClapTrap	copy(clap);
	ClapTrap	assigned;

	assigned = clap;

	std::cout << std::endl << "--- normal actions ---" << std::endl;
	clap.attack("a bandit");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << std::endl << "--- running out of energy (10 energy points) ---" << std::endl;
	ClapTrap	tired("Tired");

	for (int i = 0; i < 10; i++)
		tired.attack("a target dummy");
	tired.attack("a target dummy");
	tired.beRepaired(5);

	std::cout << std::endl << "--- running out of hit points ---" << std::endl;
	ClapTrap	fragile("Fragile");

	fragile.takeDamage(4);
	fragile.takeDamage(100);
	fragile.takeDamage(1);
	fragile.attack("anyone");
	fragile.beRepaired(10);

	std::cout << std::endl << "--- destruction (reverse order of construction) ---" << std::endl;
	return (0);
}
