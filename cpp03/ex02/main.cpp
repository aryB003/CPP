#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- construction order: ClapTrap first, then FragTrap ---" << std::endl;
	FragTrap	frag("Fraggy");

	std::cout << std::endl << "--- FragTrap actions (100 HP, 100 EP, 30 AD) ---" << std::endl;
	frag.attack("a bandit");
	frag.takeDamage(40);
	frag.beRepaired(15);
	frag.highFivesGuys();

	std::cout << std::endl << "--- copy constructor and copy assignment ---" << std::endl;
	FragTrap	copy(frag);
	FragTrap	assigned;

	assigned = frag;
	copy.highFivesGuys();

	std::cout << std::endl << "--- running out of hit points ---" << std::endl;
	FragTrap	fragile("Fragile");

	fragile.takeDamage(500);
	fragile.attack("anyone");
	fragile.highFivesGuys();

	std::cout << std::endl << "--- all three classes side by side ---" << std::endl;
	ClapTrap	clap("Clappy");
	ScavTrap	scav("Scavvy");

	clap.attack("Fraggy");
	scav.attack("Fraggy");
	frag.attack("Scavvy");
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << std::endl << "--- destruction (reverse order of construction) ---" << std::endl;
	return (0);
}
