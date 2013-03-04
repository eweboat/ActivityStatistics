#pragma once
#include <string>

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
	virtual std::string GenerateImpl() const;
};

class TopActionsReport : public Report
{
public:
	TopActionsReport(unsigned int numRequired) : m_numActionsRequired(numRequired) {}

private:
	virtual std::string GenerateImpl() const;
	unsigned int		m_numActionsRequired;
};