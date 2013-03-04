#include "CommandLineInterpreter.h"
#include <sstream>

bool ParseCommandLineInstructions(const std::vector<std::string>& argVector)
{
	unsigned int num;
	int negativeTestVal;
	std::stringstream ss; 
	ss << argVector.at(0);
	ss >> num;
	ss.seekg(0);
	ss >> negativeTestVal;
	if (ss.fail()) 
	{
		throw std::runtime_error("could not read index value in command line argument: " + argVector.at(0) + "\n");
	}
	//if (targetIndex < OperationLimits::MinQueryArg)
	//{
	//	throw std::runtime_error("index arguement must be greater than zero (" + argVector.at(0) + ")\n");
	//}
	if (negativeTestVal < 0)
	{
		throw std::runtime_error("index arguement must be positive (" + argVector.at(0) + ")\n");
	}

	return true;
}


