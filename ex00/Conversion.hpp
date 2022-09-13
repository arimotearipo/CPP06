#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include <limits>
#include <sstream>
#include <cmath>
#include "colours.h"

#define TYPEINVALID	0
#define TYPEPSEUDO	1
#define TYPECHAR 	2
#define TYPEINT		3
#define TYPEFLOAT	4
#define TYPEDOUBLE	5

using std::string;
using std::ostream;

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
		void	convertChar(void);
		void	convertNumeric(void);
		// void	convertFloat(void);
		// void	convertDouble(void);
		void	handlePseudoLiterals(void);
		void	validify(void);

		//getters
		char	getChar(void);
		int		getInt(void);
		float	getFloat(void);
		double	getDouble(void);
		string	&getFloatLiteral(void);
		string	&getDoubleLiteral(void);
		//getters end

		bool	charDisplayable = true;
		bool	charValid = false;
		bool	intValid = false;
		bool	floatValid = false;
		bool	doubleValid = false;
		bool	isPseudoLiteral = false;

	private:
		string	arg;
		int		type;
		char	valueChar;
		int		valueInt;
		float	valueFloat;
		double	valueDouble;

		string	floatLiteral;
		string	doubleLiteral;
};

ostream	&operator<<(ostream &OS, Conversion &toprint);

bool	isChar(char const *arg);
bool	isInt(char const *arg);
bool	isFloat(char const *arg);
bool	isDouble(char const *arg);
bool	isPseudoLiterals(char const *arg);

bool	charInRange(string const &arg);
bool	intInRange(string const &arg);
bool	floatInRange(string const &arg);
bool	doubleInRange(string const &arg);

#endif
