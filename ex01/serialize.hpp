#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <ostream>
#include <stdint.h>
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
		string const	&getName(void) const;
		//getters end

	private:
		string	_name;
		int		_sides;
		int		_vertices;
};

ostream	&operator<<(ostream &OS, Data const &DATA);

#endif