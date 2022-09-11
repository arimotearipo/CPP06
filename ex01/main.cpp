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
	Data *a = new Data("triangle", 3, 3);
	cout << "Address of original Data type instantiated: " << a << endl;

	uintptr_t	ser = serialize(a);

	cout << "Serialized into uintptr_t type" << endl;
	cout << ser << endl;
	cout << "Address of serialized uintptr_t type: " << &ser << endl;

	Data *des = deserialize(ser);
	cout << "Deserialized into Data type" << endl;
	cout << *des << endl;
	cout << "Address of deserialized Data type: " << &des << endl;

	delete a;
	return (0);
}