#include <iostream>
#include <vector>
#include <string>
#include <boost\lexical_cast.hpp>
#include <chrono>
#include "CommandLineInterpreter.h"
#include "DataReader.h"

int main(int argc, char** argv)
{
	try
	{
		ReadInputFile("example_input.txt");

		// take initial time stamp
		using std::chrono::high_resolution_clock;
		high_resolution_clock::time_point startTime = high_resolution_clock::now();

		// put build array out of command line args and process
		{
			std::vector<std::string> argVector(argv+1, argv + argc);
			if (argVector.empty())
			{
				throw std::runtime_error("invalide number of arguements (" + boost::lexical_cast<std::string>(argVector.size()) + ")\n");
			}
			//ParseCommandLineInstructions(argVector);
		}

		// Populate list of primes
		//std::vector<unsigned int> orderedLeftPrimes;
		//FindLeftTruncatablePrimes(orderedLeftPrimes, targetIndex);

		// take post time stamp
		high_resolution_clock::time_point endTime = high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);

		// output results
		//unsigned int indexTrailingDigit = targetIndex % 10;
		//std::string ordinality = "th";
		//ordinality = indexTrailingDigit == 1 ? "st" : ordinality;
		//ordinality = indexTrailingDigit == 2 ? "nd" : ordinality;
		//ordinality = indexTrailingDigit == 3 ? "rd" : ordinality;
		//std::cout << "result : the " << targetIndex << ordinality << " left truncatable prime = " << orderedLeftPrimes.at(targetIndex-1) << "\n";
		std::cout << "execution time: " << time_span.count() << " seconds.\n";

    }
	catch (std::logic_error& ex)
	{
		std::cerr << "A systematic error has occured: " << ex.what() << "\nExiting...\n" << std::endl;
	}
	catch (std::runtime_error& ex)
	{
		std::cerr << "An runtime error has occured: " << ex.what() << "\nExiting...\n" << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << "An unexpected error occured: " << ex.what() << "\nExiting...\n" << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unexpected error occured: Exiting...\n" << std::endl;
	}

	std::cout << "Press enter key to exit\n";
	std::cin.get();
	return 0;
}