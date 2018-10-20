#pragma once
#include <string>

#include <ArgumentParser.hpp>
#include "Common.h"

namespace hnStat
{

class ArgumentParser
{
	int numberOfArguments;
	char **arguments;
	TreatmentType type;
	std::string fileName;
	std::size_t fromTimestamp, toTimestamp, numberOfTopQueries;
public:
	ArgumentParser(int argc, char **argv);
	
	bool Initialize();
	
	void PrintHelp();
	
	TreatmentType getType() const;
	
	const std::string &getFileName() const;
	
	const size_t &getFromTimestamp() const;
	
	const size_t &getToTimestamp() const;
	
	const size_t getNQueries() const;
	
	~ArgumentParser();

};

}

