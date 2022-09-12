#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

using std::cout;
using std::endl;

Base	*generate(void)
{

	Base	*stuff;
	srand(time(0));
	int	randomnumber = rand() % 3;
	if (randomnumber == 0)
		stuff = new A;
	else if (randomnumber == 1)
		stuff = new B;
	else
		stuff = new C;
	cout << BLU << "Random number generated: " << randomnumber << RESET << endl;
	return (stuff);
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A*>(ptr) != NULL)
	{
		cout << GRN << "Type A" << RESET << endl;
		return ;
	}
	else if (dynamic_cast<B*>(ptr) != NULL)
	{
		cout << GRN << "Type B" << RESET << endl;
		return ;
	}
	else if (dynamic_cast<C*>(ptr) != NULL)
	{
		cout << GRN << "Type C" << RESET << endl;
		return ;
	}
}

void	identify(Base &obj)
{
	try
	{
		(void)dynamic_cast<A&>(obj);
		cout << GRN << "Type A" << RESET << endl;
	}
	catch (std::bad_cast) {}

	try
	{
		(void)dynamic_cast<B&>(obj);
		cout << GRN << "Type B" << RESET << endl;
	}
	catch (std::bad_cast) {}

	try
	{
		(void)dynamic_cast<C&>(obj);
		cout << GRN << "Type C" << RESET << endl;
	}
	catch (std::bad_cast) {}
}

int	main(void)
{
	Base *test;

	srand(time(NULL));
	test = generate();
	identify(test);
	identify(*test);
	delete test;
	return (0);
}