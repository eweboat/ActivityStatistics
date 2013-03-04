#include "Report.h"

std::string TotalActionsPerSiteReport::GenerateImpl() const 
{ 
	return "I am a TotalActionsPerSiteReport report\n"; 
} 

std::string MeanSessionsReport::GenerateImpl() const 
{ 
	return "I am a MeanSessionsReport report\n"; 
} 

std::string TopActionsReport::GenerateImpl() const 
{ 
	return "I am a TopActionsReport report\n"; 
} 
