#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon	empty = Weapon("");

		HumanA	ann("Ann", empty);
		HumanB	tom("Tom");
		ann.attack();
		tom.attack();
		tom.setWeapon(empty);
		tom.attack();
		empty.setType("giant laser");
		ann.attack();
		tom.attack();
	}
	return (0);
}
