#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap = newZombie("HeapZombie");

	heap->announce();
	randomChump("StackZombie");
	delete heap;
	return (0);
}
