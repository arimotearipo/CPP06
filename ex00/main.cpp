#include "Conversion.hpp"

using std::cout;
using std::endl;

int	main(int ac, char **av)
{
	// (void)ac;
	// (void)av;
	// cout << std::numeric_limits<int>::max() << endl;
	// cout << std::numeric_limits<float>::max() << endl;
	// cout << std::numeric_limits<double>::max() << endl;
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
max double: 1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
max float: 3402820000000000000000000000000000000000
*/