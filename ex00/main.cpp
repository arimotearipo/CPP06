#include "Conversion.hpp"

using std::cout;
using std::endl;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << RED << "Must take one argument" << RESET << endl;
		return (1);
	}
	Conversion con(av[1]);
	con.showType();
	// int t = av[1][0];
	// cout << "isdigit " << isdigit(t) << endl;

	return (0);
}