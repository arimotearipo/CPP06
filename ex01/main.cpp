#include "serialize.hpp"

using std::cout;
using std::endl;

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	cout << UWHT "Creating an instance of Data..." RESET << endl;
	Data *a = new Data("triangle", 3, 3);
	cout << endl;

	cout << UWHT "Printing the content of the instantiated Data object..." RESET << endl;
	cout << *a << endl;
	cout << endl;

	cout << UWHT "Printing the address of the instance of Data..." RESET << endl;
	cout << "Address of original Data type instantiated: " << GRN << a << RESET << endl;
	cout << endl;

	cout << UWHT "Using serialize() on the instance of Data..." RESET << endl;
	uintptr_t	ser = serialize(a);
	cout << "Serialized into uintptr_t type" << endl;
	cout << endl;

	cout << UWHT << "Printing the serialized Data..." RESET << endl;
	cout << ser << endl;
	cout << endl;

	cout << UWHT << "Printing address of serialized Data..." RESET << endl;
	cout << "Address of serialized uintptr_t type: " << GRN << &ser << RESET << endl;
	cout << endl;

	cout << UWHT << "Using deserialize on the uintptr_t type..." << RESET << endl;
	Data *des = deserialize(ser);
	cout << "Deserialized into Data type" << endl;
	cout << endl;

	cout << UWHT << "Printing the deserialized uintptr_t..." RESET << endl;
	cout << *des << endl;
	cout << endl;

	cout << UWHT "Printing the address of deserialized uintptr_t..." RESET << endl;
	cout << "Address of deserialized Data type: " << GRN << &des << GRN << endl;
	cout << endl;

	cout << UWHT "Deleting the created object..." RESET << endl;
	delete a;
	cout << endl;
	return (0);
}