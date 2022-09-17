#include "serialize.hpp"

using std::cout;
using std::endl;
using std::ostream;

Data::Data(void) : _name(""), _sides(0), _vertices(0)
{
	cout << BBLU "[DATA CLASS CONSTRUCTED]" << RESET << endl;
}

Data::Data(string name, int sides, int vertices) : _name(name), _sides(sides), _vertices(vertices)
{
	cout << BBLU "[DATA CLASS CONSTRUCTED WITH PARAMETERS" << RESET << endl;;
}

Data::Data(Data const &tocopy) : _name(tocopy.getName()), _sides(tocopy.getSides()), _vertices(tocopy.getVertices())
{
	cout << BBLU "[DATA CLASS CONSTRUCTED BY COPY" << RESET << endl;;
}

Data	&Data::operator=(Data const &toassign)
{
	if (this != &toassign)
		*this = toassign;
	return (*this);
}

Data::~Data(void)
{
	cout << BRED "[DATA CLASS DECONSTRUCTED]" << RESET << endl;;
}

// getters
int	Data::getSides(void) const
{
	return (this->_sides);
}

int	Data::getVertices(void) const
{
	return (this->_vertices);
}

const string	&Data::getName(void) const
{
	return (this->_name);
}
// getters end

ostream &operator<<(ostream &OS, Data const &DATA)
{
	OS << "Name: " << DATA.getName() << endl;
	OS << "Sides: " << DATA.getSides() << endl;
	OS << "Vertices: " << DATA.getVertices();
	return (OS);
}