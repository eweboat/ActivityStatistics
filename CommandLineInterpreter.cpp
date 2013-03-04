#include "CommandLineInterpreter.h"
#include <sstream>
#include "Report.h"

namespace CommandLine
{
static const std::string totalActionsToken("totalactions");
static const std::string meanActionsSessionToken("meansessionacctions");
static const std::string topActionsToken("topactions");

// digest vector of string arguments and insert report objects into inout reports vector
// throws: on data error
void ParseCommandLineInstructions(const std::vector<std::string>& argVector, std::vector<Report*>& reports)
{
	for (auto iter = argVector.begin(); iter != argVector.end(); ++iter)
	{
		if (*iter == totalActionsToken)
		{
			reports.push_back(new TotalActionsPerSiteReport) ;
		}
		else if (*iter == meanActionsSessionToken)
		{
			reports.push_back(new MeanSessionsReport) ;
		}
		else if (*iter == topActionsToken)
		{
			if (++iter == argVector.end())
			{
				throw std::runtime_error("when specifying \""+topActionsToken 
					+"\" require positive integer as next arguement");
			}
			unsigned int val = GetIntegerFromString(*iter);
			reports.push_back(new TopActionsReport(val)) ;
		}
		else
		{
			throw std::runtime_error("invalid arguement: " + *iter);
		}
	}
}

// convert string to unsigned int
// throw on on bad data and negative value
unsigned int GetIntegerFromString(const std::string& data)
{
	unsigned int num;
	int negativeTestVal;
	std::stringstream ss; 
	ss << data;
	ss >> num;
	ss.seekg(0);
	ss >> negativeTestVal;
	if (ss.fail()) 
	{
		throw std::runtime_error("could not read index value in command line argument: " + data + "\n");
	}
	if (negativeTestVal < 0)
	{
		throw std::runtime_error("index arguement must be positive (" + data + ")\n");
	}
	return num;
}

}