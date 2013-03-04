#pragma once
#include <map>
#include <vector>
#include <string>

// typedefs for clarity (and less typing ... or is that more types? :P )
typedef std::pair<std::string, unsigned int> StringInt;
typedef std::vector<StringInt> StringIntVec;
typedef std::map<std::string, unsigned int> AttributeTracker;
typedef std::map< std::string, AttributeTracker> MappedAttributeTracker;

