#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <ostream>
#include "colours.h"

using std::string;
using std::ostream;

class	Data
{
	public:
		Data(void);
		Data(string name, int sides, int vertices);
		Data(Data const &tocopy);
		Data &operator=(Data const &toassign);
		~Data(void);

		//getters
		int				getSides(void) const;
		int				getVertices(void) const;
		const string	&getName(void) const;
		//getters end

	private:
		int		_sides;
		int		_vertices;
		string	_name;
};

ostream	&operator<<(ostream &OS, Data const &DATA);

#endif