#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int		N = 5;
	Zombie	*horde;

	std::cout << "--- invalid hordes ---" << std::endl;
	horde = zombieHorde(0, "Walker");
	horde = zombieHorde(-3, "Walker");
	horde = zombieHorde(N, "");

	std::cout << "--- valid horde of " << N << " ---" << std::endl;
	horde = zombieHorde(N, "Walker");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
