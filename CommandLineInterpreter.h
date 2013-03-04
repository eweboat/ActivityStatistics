#pragma once
#include <vector>
#include <string>

class Report;

namespace CommandLine
{
// use functions to process command line args into set of report objects
void ParseCommandLineInstructions(const std::vector<std::string>& argVector, std::vector<Report*>& reports);
unsigned int GetIntegerFromString(const std::string& data);
}