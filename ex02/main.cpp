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
	srand(time(NULL));
	int	randomnumber = rand() % 3;
	if (randomnumber == 0)
		stuff = new A;
	else if (randomnumber == 1)
		stuff = new B;
	else
		stuff = new C;
	cout << BLU << "Random number generated: " << randomnumber << RESET << endl << endl;;
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
		dynamic_cast<A&>(obj);
		cout << GRN << "Type A" << RESET << endl;
	}
	catch (...) {}

	try
	{
		dynamic_cast<B&>(obj);
		cout << GRN << "Type B" << RESET << endl;
	}
	catch (...) {}

	try
	{
		dynamic_cast<C&>(obj);
		cout << GRN << "Type C" << RESET << endl;
	}
	catch (...) {}
}

int	main(void)
{
	Base *test;

	srand(time(NULL));
	test = generate();
	cout << UWHT << "Identifying by passing reference as parameter..." << endl;
	identify(test);
	cout << endl;
	cout << UWHT << "Identifying by passing pointer as parameter..." << endl;
	identify(*test);
	cout << endl;
	cout << UWHT << "Deleting the Base object returned by generate()..." << endl;
	delete test;
	return (0);
}