#pragma once
#include <vector>
#include <string>

class RawData;

class DataStore
{
public:
	static DataStore& GetInstance();
	void Insert(const std::string& sessionId, const std::string& websiteId, const std::string& action);
	void Insert(const RawData& data);

private:
	DataStore( ) {}
	~DataStore() {}
	DataStore(DataStore const&);		//= delete 
	void operator=(DataStore const&);	//= delete 

	static DataStore*			s_instance;
	std::vector<RawData*>		m_rawData;
};