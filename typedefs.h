#pragma once
#include <map>
#include <vector>
#include <string>

typedef std::pair<std::string, unsigned int> StringInt;
typedef std::vector<StringInt> StringIntVec;
typedef std::map<std::string, unsigned int> AttributeTracker;
typedef std::map< std::string, AttributeTracker> MappedAttributeTracker;

