#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "colours.h"

#define TYPEINVALID	0
#define TYPECHAR 	1
#define TYPEINT		2
#define TYPEFLOAT	3
#define TYPEDOUBLE	4

using std::string;

class Conversion
{
	public:
		Conversion(void);
		Conversion(char const *argument);
		Conversion	&operator=(Conversion const &toassign);
		Conversion(Conversion const &tocopy);
		~Conversion(void);

		void	showType(void);
		void	convertAll(void);

	private:
		string	_arg;
		int		_type;
		int		_valueInt;
		float	_valueFloat;
		double	_valueDouble;
};

bool	isChar(char const *arg);
bool	isInt(char const *arg);
bool	isFloat(char const *arg);
bool	isDouble(char const *arg);
int		isPseudoLiterals(char const *arg);

#endif
