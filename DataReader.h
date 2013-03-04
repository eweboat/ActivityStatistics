#pragma once
#include <string>
#include <vector>
#include <boost\tokenizer.hpp>

class DataReader
{
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	public:
		std::string const& operator[](std::size_t index) const;
		std::string const& at(std::size_t index) const;
		std::size_t size() const;
		void readNextRow(std::istream& str);
	private:
		std::vector<std::string>    m_data;
};

std::istream& operator>>(std::istream& str,DataReader& data);
void ReadInputFile(const std::string& datafile);
