#pragma once
#include <string>

////////////////////////////////////////////////////////////////////////////
//
// Class: RawData
// Purpose: simple storage mechanism that mirrors source data
//
////////////////////////////////////////////////////////////////////////////

class RawData
{
public:
	RawData(const std::string& sessionId, const std::string& websiteId, const std::string& action) :
		m_sessionId(sessionId), m_websiteId(websiteId), m_action(action) {}
	// use default copy, assignment and delete

	const std::string& GetSessionId() const { return m_sessionId; }
	const std::string& GetWebsiteId() const { return m_websiteId; }
	const std::string& GetAction() const { return m_action; }

private:
	std::string			m_sessionId;
	std::string			m_websiteId;
	std::string			m_action;
};