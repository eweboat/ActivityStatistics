#include "Report.h"
#include <boost\lexical_cast.hpp>
#include "typedefs.h"
#include "DataStore.h"

std::string TotalActionsPerSiteReport::GenerateImpl() const 
{ 
	std::string reportData("Total number of actions per website:\n");
	const AttributeTracker& websiteActionTracker = DataStore::GetInstance().GetWebsiteActionTracker();
	auto iter = websiteActionTracker.begin();
	for ( ; iter != websiteActionTracker.end(); ++iter)
	{
		std::string line(" * " + iter->first);
		if (line.size() < PadLengthTo)
		{
			line.resize(PadLengthTo, ' ');
		}
		line += ": " + boost::lexical_cast<std::string>(iter->second) + "\n";
		reportData += line;
	}
	return reportData; 
} 

std::string MeanSessionsReport::GenerateImpl() const 
{ 
	return "I am a MeanSessionsReport report\n"; 
} 

std::string TopActionsReport::GenerateImpl() const 
{ 
	return "I am a TopActionsReport report\n"; 
} 
