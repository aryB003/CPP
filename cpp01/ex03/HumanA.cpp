#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	if (_weapon.getType().empty())
		std::cout << _name << " has nothing to attack with" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
