#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- construction order: ClapTrap first, then ScavTrap ---" << std::endl;
	ScavTrap	scav("Scavvy");

	std::cout << std::endl << "--- ScavTrap actions (100 HP, 50 EP, 20 AD) ---" << std::endl;
	scav.attack("an intruder");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << std::endl << "--- copy constructor and copy assignment ---" << std::endl;
	ScavTrap	copy(scav);
	ScavTrap	assigned;

	assigned = scav;
	copy.attack("a copy target");

	std::cout << std::endl << "--- running out of hit points ---" << std::endl;
	ScavTrap	fragile("Fragile");

	fragile.takeDamage(1000);
	fragile.attack("anyone");
	fragile.beRepaired(10);
	fragile.guardGate();

	std::cout << std::endl << "--- a plain ClapTrap still uses its own attack ---" << std::endl;
	ClapTrap	clap("Clappy");

	clap.attack("a bandit");

	std::cout << std::endl << "--- destruction: ScavTrap part first, then ClapTrap part ---" << std::endl;
	return (0);
}
