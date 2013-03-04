#include <iostream>
#include <vector>
#include <string>
#include <boost\lexical_cast.hpp>
#include <chrono>
#include "CommandLineInterpreter.h"
#include "DataReader.h"
#include "DataStore.h"
#include <fstream>

#include "Report.h"

static const std::string inputDataFile = "example_input.txt";

void ReadInputFile(const std::string& datafile)
{
	std::ifstream file(datafile);
	DataReader row;
	DataStore& dataStore = DataStore::GetInstance();
	while (file >> row)
	{
		try
		{
			dataStore.Insert(row.at(0), row.at(1), row.at(2));
		}
		catch(...)
		{
			// do nothing on exception but allow rest of data to ingested
		}
	}
}

int main(int argc, char** argv)
{
	try
	{
		// take initial time stamp
		using std::chrono::high_resolution_clock;
		high_resolution_clock::time_point startTime = high_resolution_clock::now();

		// store required reports in vector
		std::vector<Report*> reports;

		// put build array out of command line args and process
		{
			std::vector<std::string> argVector(argv+1, argv + argc);
			if (argVector.empty())
			{
				throw std::runtime_error("invalide number of arguements (" + boost::lexical_cast<std::string>(argVector.size()) + ")\n");
			}
			CommandLine::ParseCommandLineInstructions(argVector, reports);
		}

		// read data file into store
		ReadInputFile(inputDataFile);

		// run reports
		std::string output;
		for (auto report : reports)
		{
			output += report->Generate() + "\n";
		}
		std::cout << output; // todo remove
		std::ofstream output_file("output.txt");
		std::ostream_iterator<char> output_iterator(output_file);
		std::copy(output.begin(), output.end(), output_iterator);
		output_file.close();	


		// take post time stamp
		high_resolution_clock::time_point endTime = high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
    }
	catch (std::logic_error& ex)
	{
		std::cerr << "A systematic error has occured: " << ex.what() << "\nExiting...\n" << std::endl;
	}
	catch (std::runtime_error& ex)
	{
		std::cerr << "A runtime error has occured: " << ex.what() << "\nExiting...\n" << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << "A unexpected error has occured: " << ex.what() << "\nExiting...\n" << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unexpected error occured: Exiting...\n" << std::endl;
	}

	return 0;
}