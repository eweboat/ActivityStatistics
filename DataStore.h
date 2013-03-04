#pragma once
#include <vector>
#include <string>
#include <map>
#include "typedefs.h"

////////////////////////////////////////////////////////////////////////////
//
// Class: DataStore
// Purpose: provide datas storage and access for reports to run against
// Comments: implemented as singleton but could equally well be accessed by
//			passed reference
//
////////////////////////////////////////////////////////////////////////////

class RawData;

class DataStore
{
public:
	static DataStore& GetInstance();
	void Insert(const std::string& sessionId, const std::string& websiteId, const std::string& action);
	void Insert(const RawData& data);

	const AttributeTracker& GetWebsiteActionTracker() const { return m_websiteActions; }
	const MappedAttributeTracker& GetWebsiteSessionActionMap() const { return m_websiteSessionActionTracker; }
	StringIntVec GetActionTrackerSorted() const;
private:
	DataStore( ) {}
	~DataStore() {}
	DataStore(DataStore const&);		//= delete 
	void operator=(DataStore const&);	//= delete 

	static DataStore*			s_instance;
	std::vector<RawData*>		m_rawData;

	AttributeTracker			m_websiteActions;
	AttributeTracker			m_actionTracker;
	MappedAttributeTracker		m_websiteSessionActionTracker;
};