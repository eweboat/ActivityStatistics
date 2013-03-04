#pragma once
#include <map>
#include <vector>
#include <string>

// typedefs for clarity (and less typing ... or is that more types? :P )
typedef std::pair<std::string, unsigned int> StringInt;
typedef std::vector<StringInt> StringIntVec;
typedef std::map<std::string, unsigned int> AttributeTracker;
typedef std::map< std::string, AttributeTracker> MappedAttributeTracker;


#include "RawData.h"

// access policies
template <class T> struct FileAccess
{
   std::vector<T> ReadData() { /* read data from file */ }
};
template <class T> struct DatabaseAccess
{
   std::vector<T> ReadData() { /* read data from database */ }
};

// revised DataStore
template
<
   class T,
   template <class> class AccessPolicy
>
class DataStore2 : public AccessPolicy<T>, public AdditionalPolicy ...
{
   //...
	void ReadData()
	{
		m_data = AccessPolicy<T>::ReadData();
	}
private:
   std::vector<T> m_data;
};

typedef DataStore2<RawData, FileAccess> DataStoreFile;
typedef DataStore2<RawData, DatabaseAccess> DataStoreDatabase;
