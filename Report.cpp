#include "Report.h"
#include <boost\lexical_cast.hpp>
#include "typedefs.h"
#include "DataStore.h"

// specialised function to query DataStore and format data into report string
std::string TotalActionsPerSiteReport::GenerateImpl() const 
{ 
	std::string reportData("Total number of actions per website:\n");
	const AttributeTracker& websiteActionTracker = DataStore::GetInstance().GetWebsiteActionTracker();
	for ( auto iter = websiteActionTracker.begin() ; iter != websiteActionTracker.end(); ++iter)
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

// specialised function to query DataStore and format data into report string
std::string MeanSessionsReport::GenerateImpl() const 
{ 
	std::string reportData("Mean number of actions in a session per website:\n");
	const MappedAttributeTracker& websiteSessionActionMap = DataStore::GetInstance().GetWebsiteSessionActionMap();
	for (auto websiteIter = websiteSessionActionMap.begin() ; websiteIter != websiteSessionActionMap.end(); ++websiteIter)
	{
		std::string line(" * " + websiteIter->first);
		if (line.size() < PadLengthTo)
		{
			line.resize(PadLengthTo, ' ');
		}
		float runningTotal = 0;
		for (auto session : websiteIter->second)
		{
			runningTotal += session.second;
		}
		line += ": " + boost::lexical_cast<std::string>(runningTotal / websiteIter->second.size()) + "\n";
		reportData += line;
	}
	return reportData; 
} 

// specialised function to query DataStore and format data into report string
std::string TopActionsReport::GenerateImpl() const 
{ 
	int lineCount = 0;
	std::string reportData(boost::lexical_cast<std::string>(m_numActionsRequired) +" most frequent actions:\n");
	StringIntVec actionTracker = DataStore::GetInstance().GetActionTrackerSorted();
	for ( auto iter = actionTracker.begin(); iter != actionTracker.end(); ++iter)
	{
		std::string line(" * " + boost::lexical_cast<std::string>(iter->second));
		if (line.size() < PadLengthTo)
		{
			line.resize(PadLengthTo, ' ');
		}
		line += ": " + iter->first + "\n";
		reportData += line;
		// only require lines of data equal to m_numActionsRequired 
		if (++lineCount == m_numActionsRequired)
		{
			break;
		}
	}
	return reportData; 
} 
