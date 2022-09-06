#include "Conversion.hpp"

using std::string;
using std::cout;
using std::endl;

Conversion::Conversion(void)
{
	this->_type = TYPEINVALID;
	cout << BLU << "[CONVERSION CLASS CONSTRUCTED]" << RESET << endl;
}

Conversion::Conversion(char const *argument)
{
	if (isChar(argument) == true)
		this->_type = TYPECHAR;
	else if (isInt(argument) == true)
		this->_type = TYPEINT;
	else if (isFloat(argument) == true)
		this->_type = TYPEFLOAT;
	else if (isDouble(argument) == true)
		this->_type = TYPEDOUBLE;
	else
		this->_type = isPseudoLiterals(argument);

	this->_arg = string(argument);
	cout << BLU << "[CONVERSION CLASS CONSTRUCTED WITH ARGUMENT]" << RESET << endl;
}

Conversion &Conversion::operator=(Conversion const &toassign)
{
	cout << BLU << "[CONVERSION CLASS CONSTRUCTED BY ASSIGNMENT]" << RESET << endl;
	return (*this);
}

Conversion::Conversion(Conversion const &tocopy)
{
	*this = tocopy;
	cout << BLU << "[CONVERSION CLASS CONSTRUCTED BY COPY]" << RESET << endl;
}

Conversion::~Conversion(void)
{
	cout << RED << "[CONVERSION CLASS DECONSTRUCTED]" << RESET << endl;
}

void	Conversion::showType(void)
{
	string		types[5] = {"Invalid type", "Char type", "Int type", "Float type", "Double type"};

	cout << types[this->_type] << endl;
}

void	Conversion::convertAll(void)
{
	this->_valueInt = stoi(this->_arg);
}

bool	isChar(char const *arg)
{
	string str(arg);

	if (str.length() > 1)
		return (false);
	if (arg[0] <= 32 && arg[0] >= 127 || isdigit(arg[0]) == 1)
		return (false);
	return (true);
}

bool	isInt(char const *arg)
{
	string str(arg);
	int		tocheck;

	tocheck = arg[0];
	if (arg[0] != '-' && isdigit(tocheck) == 0)
		return (false);
	for (int i = 1; i < str.length(); i++)
	{
		tocheck = str[i];
		if (isdigit(tocheck) == 0)
			return (false);
	}
	return (true);
}

bool	isFloat(char const *arg)
{
	string str(arg);
	int		tocheck;
	int		decimalcount = 0;

	tocheck = arg[0];
	if (arg[0] != '-' && isdigit(tocheck) == 0)
		return (false);
	for (int i = 1; i < str.length() - 1; i++)
	{
		tocheck = str[i];
		if (str[i] == '.')
		{
			decimalcount++;
			continue ;
		}
		if (isdigit(tocheck) == 0 || decimalcount > 1)
			return (false);
	}
	if (str[str.length() - 1] != 'f')
		return (false);
	return (true);
}

bool	isDouble(char const *arg)
{
	string str(arg);
	int		tocheck;
	int		decimalcount = 0;

	tocheck = arg[0];
	if (arg[0] != '-' && isdigit(tocheck) == 0)
		return (false);
	for (int i = 1; i < str.length() - 1; i++)
	{
		tocheck = str[i];
		if (str[i] == '.')
		{
			decimalcount++;
			continue ;
		}
		if (isdigit(tocheck) == 0 || decimalcount > 1)
			return (false);
	}
	return (true);
}

int		isPseudoLiterals(char const *arg)
{
	string	floatpseudo[3] = {"-inff", "+inff", "nanf"};
	string	doublepseudo[3] = {"-inf", "+inf", "nan"};
	string	str(arg);

	for (int i = 0; i < 3; i++)
	{
		if (str == floatpseudo[i])
			return (TYPEFLOAT);
		else if (str == doublepseudo[i])
			return (TYPEDOUBLE);
	}
	return (TYPEINVALID);
}