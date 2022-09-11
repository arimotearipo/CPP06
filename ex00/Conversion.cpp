#include "Conversion.hpp"

using std::string;
using std::cout;
using std::endl;
using std::stoi;
using std::stof;
using std::stod;

Conversion::Conversion(void)
{
	this->type = TYPEINVALID;
	cout << BLU << "[CONVERSION CLASS CONSTRUCTED]" << RESET << endl;
}

Conversion::Conversion(char const *argument) : arg(argument)
{
	bool (*funcptr[5])(char const *argstr) = {&isPseudoLiterals, &isChar, &isInt, &isFloat, &isDouble};
	for (int i = 0; i < 5; i++)
	{
		if ((funcptr[i])(argument) == true)
		{
			this->type = i + 1;
			break ;
		}
		this->type = TYPEINVALID;
	}
	// To accept inputs like -.3f or .3 where it should be translated as -0.3f and 0.3 respectively
	if (this->arg[0] == '.')
		this->arg.replace(0, 1, "0.");
	else if (this->arg[0] == '-' && this->arg[1] == '.')
		this->arg.replace(0, 2, "-0.");
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
	string		types[6] = {"Invalid type", "Pseudo literal type", "Char type", "Int type", "Float type", "Double type"};

	cout << types[this->type] << endl;
}

void	Conversion::convertChar(void)
{
	char c = (this->arg)[0];
	this->valueChar = static_cast<char>(c);
	this->valueInt = static_cast<int>(c);
	this->valueFloat = static_cast<float>(c);
	this->valueDouble = static_cast<double>(c);
	this->charValid = true;
	this->intValid = true;
	this->floatValid = true;
	this->doubleValid = true;
}

void	Conversion::convertNumeric(void)
{
	int	save = -1;
	bool	(*functPtr[4])(string const &arg) = {&doubleInRange, &floatInRange, &intInRange, &charInRange};

	for (int i = 0; i < 4; i++)
	{
		if ((*functPtr[i])(this->arg) == true)
			save++;
		else
			break ;
	}
	cout << "save: " << save << endl;
	switch (save)
	{
		case (3):
			this->valueChar = static_cast<char>(stoi(this->arg));
		case (2):
			this->valueInt = static_cast<int>(stoi(this->arg));
		case (1):
			this->valueFloat = static_cast<float>(stof(this->arg));
		case (0):
			this->valueDouble = static_cast<double>(stod(this->arg));
	}
}

void	Conversion::handlePseudoLiterals(void)
{
	if (this->type != TYPEPSEUDO)
		return ;
	string	floatpseudo[3] = {"-inff", "+inff", "nanf"};
	string	doublepseudo[3] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++)
	{
		if (this->arg == floatpseudo[i] || this->arg == doublepseudo[i])
		{
			this->isPseudoLiteral = true;
			this->charValid = false;
			this->intValid = false;
			this->floatLiteral = floatpseudo[i];
			this->doubleLiteral = doublepseudo[i]; 
		}
	}
}

void	Conversion::validify(void)
{
	int	save = -1;
	bool	(*functPtr[4])(string const &arg) = {&doubleInRange, &floatInRange, &intInRange, &charInRange};

	for (int i = 0; i < 4; i++)
	{
		if ((*functPtr[i])(this->arg) == true)
			save++;
		else
			break ;
	}
	switch (save)
	{
		case (3):
			this->charValid = true;
		case (2):
			this->intValid = true;
		case (1):
			this->floatValid = true;
		case (0):
			this->doubleValid = true;
	}
}

void	Conversion::convertAll(void)
{
	if (this->type == TYPEINVALID)
		return ;
	if (this->type == TYPEPSEUDO)
		this->handlePseudoLiterals();
	else if (this->type == TYPECHAR)
		this->convertChar();
	else
		this->convertNumeric();
	this->validify();
	if (this->valueChar <= 32 || this->valueChar == 127)
		this->charDisplayable = false;
}

//getters
char	Conversion::getChar(void)
{
	return (this->valueChar);
}

int		Conversion::getInt(void)
{
	return (this->valueInt);
}

float	Conversion::getFloat(void)
{
	return (this->valueFloat);
}

double	Conversion::getDouble(void)
{
	return (this->valueDouble);
}

string	&Conversion::getFloatLiteral(void)
{
	return (this->floatLiteral);
}

string	&Conversion::getDoubleLiteral(void)
{
	return (this->doubleLiteral);
}
//getters end


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

// bool	isFloat(char const *arg)
// {
// 	string str(arg);
// 	int		tocheck;
// 	int		decimalcount = 0;

// 	tocheck = arg[0];
// 	if (tocheck != '-' && isdigit(tocheck) == 0)
// 		return (false);
// 	cout << "WHAT?\n";
// 	for (int i = 1; i < str.length() - 1; i++)
// 	{
// 		tocheck = str[i];
// 		if (str[i] == '.')
// 		{
// 			decimalcount++;
// 			continue ;
// 		}
// 		if (isdigit(tocheck) == 0 || decimalcount > 1)
// 			return (false);
// 	}
// 	if (str[str.length() - 1] != 'f')
// 		return (false);
// 	return (true);
// }

// bool	isDouble(char const *arg)
// {
// 	string str(arg);
// 	int		tocheck;
// 	int		decimalcount = 0;

// 	tocheck = arg[0];
// 	if (tocheck != '-' && isdigit(tocheck) == 0)
// 		return (false);
// 	for (int i = 1; i < str.length(); i++)
// 	{
// 		tocheck = str[i];
// 		if (str[i] == '.')
// 		{
// 			decimalcount++;
// 			continue ;
// 		}
// 		if (isdigit(tocheck) == 0 || decimalcount != 1)
// 			return (false);
// 	}
// 	return (true);
// }

bool	isFloat(char const *arg)
{
	string	argstr(arg);
	if (argstr[0] == '.')
		argstr.replace(0, 1, "0.");
	else if (argstr[0] == '-' && argstr[1] == '.')
		argstr.replace(0, 2, "-0.");
	char	*end = nullptr;
	double	val = strtof(argstr.c_str(), &end);
	return (end != argstr.c_str() && *end == 'f' && *(end + 1) == '\0' && val != HUGE_VAL);
}

bool	isDouble(char const *arg)
{
	string	argstr(arg);
	if (argstr[0] == '.')
		argstr.replace(0, 1, "0.");
	else if (argstr[0] == '-' && argstr[1] == '.')
		argstr.replace(0, 2, "-0.");
	char	*end = nullptr;
	double	val = strtod(argstr.c_str(), &end);
	return (end != argstr.c_str() && *end == '\0' && val != HUGE_VAL);
}

bool	isPseudoLiterals(char const *arg)
{
	string	floatpseudo[3] = {"-inff", "+inff", "nanf"};
	string	doublepseudo[3] = {"-inf", "+inf", "nan"};
	string	str(arg);

	for (int i = 0; i < 3; i++)
	{
		if (str == floatpseudo[i] || str == doublepseudo[i])
			return (true);
	}
	return (false);
}

bool	charInRange(string const &arg)
{
	try
	{
		int value = static_cast<int>(stoi(arg));
		return (value >= 0 && value <= 127);
	}
	catch (std::invalid_argument)
	{
		char value = arg[0];
		return (value >= 0 && value <= 127);
	}
}

bool	intInRange(string const &arg)
{
	try
	{
		int value = static_cast<int>(stoi(arg));
		return (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
	}
	catch (std::out_of_range)
	{
		return (false);
	}
}

bool floatInRange(string const &arg)
{
	try
	{
		float value = stof(arg);
		return (value >= (std::numeric_limits<float>::max() * -1) && value <= std::numeric_limits<float>::max());
	}
	catch (std::out_of_range)
	{
		return (false);
	}
}

bool doubleInRange(string const &arg)
{
	// There are two possible errors that could occur in the try block
	// First is the out_of_range error (for if the arg is out of range)
	// Second is the invalid_argument (for if the arg is a char)
	// The usage of (...) in the catch block means it's just going to catch whatever exceptions thrown
	// I do not need to do this for floatInRange() and intInRange() because I always call these functions
	// in a flow from doubleInRange > floatInRange > intInRange by using the switch statement
	try
	{
		double value = stod(arg);
		return (value >= (std::numeric_limits<double>::max() * -1) && value <= std::numeric_limits<double>::max());
	}
	catch (...)
	{
		return (false);
	}
}

ostream	&operator<<(ostream &OS, Conversion &toprint)
{
	//printing char
	if (toprint.charDisplayable == false && toprint.charValid == true)
		OS << "char: non displayable" << endl;
	else if (toprint.charValid == false)
		OS << "char: impossible" << endl;
	else if (toprint.charDisplayable == true && toprint.charValid == true)
		OS << "char: " << toprint.getChar() << endl;

	//printing int
	if (toprint.intValid == true)
		OS << "int: " << toprint.getInt() << endl;
	else
		OS << "int: impossible" << endl;
	
	// printing float
	if (toprint.floatValid == true && toprint.isPseudoLiteral == false)
		OS << "float: " << std::fixed << std::setprecision(1) << toprint.getFloat() << "f" << endl;
	else if (toprint.isPseudoLiteral == true)
		OS << "float: " << toprint.getFloatLiteral() << endl;
	else
		OS << "float: impossible" << endl;
	
	// printing double
	if (toprint.doubleValid == true && toprint.isPseudoLiteral == false)
		OS << "double: " << std::fixed << std::setprecision(1) << toprint.getDouble();
	else if (toprint.isPseudoLiteral == true)
		OS << "double: " << toprint.getDoubleLiteral();
	else
		OS << "double: impossible";

	return (OS);
}