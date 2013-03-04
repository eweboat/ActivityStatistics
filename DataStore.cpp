#include "DataStore.h"
#include <algorithm>
#include "RawData.h"

DataStore* DataStore::s_instance = nullptr;

DataStore& DataStore::GetInstance()
{ 
	if (!s_instance)
	{
		s_instance = new DataStore;
	}
	return *s_instance; 
}

void DataStore::Insert(const std::string& sessionId, const std::string& websiteId, const std::string& action)
{
	RawData* data = new RawData(sessionId, websiteId, action);
	m_rawData.push_back(data);

	// copy data into specialised data structure to aid report generation
	m_websiteActions[websiteId] = m_websiteActions[websiteId] + 1;
	m_actionTracker[action] = m_actionTracker[action] + 1;
	m_websiteSessionActionTracker[websiteId][sessionId] = m_websiteSessionActionTracker[websiteId][sessionId] + 1;
}

void DataStore::Insert(const RawData& data)
{
	Insert(data.GetSessionId(), data.GetWebsiteId(), data.GetAction());
}

StringIntVec DataStore::GetActionTrackerSorted() const 
{ 
	// copy data into vector and pass back as sorted return value
	StringIntVec actionTrackerVec;
	for( auto it = m_actionTracker.begin(); it != m_actionTracker.end(); ++it ) {
    	actionTrackerVec.push_back( *it );
    }
	std::sort (actionTrackerVec.begin(), actionTrackerVec.end(), 
		[](const StringInt& lhs, const StringInt& rhs){return rhs.second < lhs.second;} );
	return actionTrackerVec; 
}