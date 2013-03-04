#include "DataStore.h"
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
}

void DataStore::Insert(const RawData& data)
{
	Insert(data.GetSessionId(), data.GetWebsiteId(), data.GetAction());
}