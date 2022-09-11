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
	con.convertAll();
	cout << con << endl;
	return (0);
}

/*
max double: 18000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
max float: 350000000000000000000000000000000000000000000000000
*/