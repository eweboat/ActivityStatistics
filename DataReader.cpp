#include "DataReader.h"
#include <fstream>
#include <sstream>
#include "DataStore.h"


void ReadInputFile(const std::string& datafile)
{
	std::ifstream file(datafile);
	DataReader row;
	DataStore& dataStore = DataStore::GetInstance();
	while (file >> row)
	{
		try
		{
			dataStore.Insert(row.at(0), row.at(1), row.at(2));
		}
		catch(...)
		{
			int i = 9;
		}
	}
}

std::string const& DataReader::at(std::size_t index) const
{
	if (index >= m_data.size())
	{
		throw std::runtime_error("out of bounds");
	}
	return m_data[index];
}

std::string const& DataReader::operator[](std::size_t index) const
{
	return m_data[index];
}

std::size_t DataReader::size() const
{
	return m_data.size();
}

void DataReader::readNextRow(std::istream& str)
{
	std::string line;
	std::getline(str,line);
	std::stringstream lineStream(line);

	m_data.clear();
	boost::char_separator<char> sep(" ");
	while(std::getline(lineStream,line))
	{
		std::string str = line;
		tokenizer tokens(line, sep);
		for (tokenizer::iterator tokenIter = tokens.begin(); tokenIter != tokens.end(); ++tokenIter)
		{
			m_data.push_back(*tokenIter);
		}
	}
}

std::istream& operator>>(std::istream& str,DataReader& data)
{
	data.readNextRow(str);
	return str;
}
