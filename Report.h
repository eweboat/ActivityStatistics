#pragma once
#include <string>

////////////////////////////////////////////////////////////////////////////
//
// Class: Report
// Purpose: Abstract base class for data analysis and output
// Specialisation: derived classes of Report must implement the GenerateImpl
//		method and may query data store when doing so
// Comments: it may be desireable for Report to store a reference to the 
//		DataStore object rather than accessing through singleton
//
////////////////////////////////////////////////////////////////////////////

class Report
{
public:
	std::string Generate() const { return GenerateImpl(); }

private:
	virtual std::string GenerateImpl() const = 0;
};


class TotalActionsPerSiteReport : public Report
{
private:
	enum { PadLengthTo = 13 };
	virtual std::string GenerateImpl() const;
};

class MeanSessionsReport : public Report
{
private:
	enum { PadLengthTo = 13 };
	virtual std::string GenerateImpl() const;
};

class TopActionsReport : public Report
{
public:
	TopActionsReport(unsigned int numRequired) : m_numActionsRequired(numRequired) {}

private:
	enum { PadLengthTo = 8 };
	virtual std::string GenerateImpl() const;

	unsigned int		m_numActionsRequired;
};