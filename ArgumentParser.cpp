#include "ArgumentParser.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <limits>

using namespace hnStat;

ArgumentParser::ArgumentParser(int argc, char **argv) : numberOfArguments(argc), arguments(argv), fromTimestamp(0), toTimestamp(std::numeric_limits<std::size_t>::max()), numberOfTopQueries(0)
{
}

bool ArgumentParser::Initialize()
{
	if(numberOfArguments < 2)
		return false;
	if( strcmp( arguments[1], "distinct" ) == 0 )
	{
		type = distinct;
	}
	else if( strcmp( arguments[1], "top" ) == 0 )
	{
		type = top;
	}
	else
		return false;
	
	bool topQueriesParsed = false;
	try{
		for( int iterArgs = 2; iterArgs < numberOfArguments; ++iterArgs )
		{
			char *currentArg = arguments[iterArgs];
			if( strcmp( currentArg, "--from" ) == 0 )
			{
				if( iterArgs + 1 < numberOfArguments )
				{
					fromTimestamp = std::stol( arguments[iterArgs+1] );
					++iterArgs;
				}
				else
					return false;
			}
			else if( strcmp( currentArg, "--to" ) == 0 )
			{
				if( iterArgs + 1 < numberOfArguments )
				{
					toTimestamp = std::stol( arguments[iterArgs+1] );
					++iterArgs;
				}
				else
					return false;
			}
			else
			{
				if(type == top && !topQueriesParsed )
				{
					numberOfTopQueries = std::stol( arguments[iterArgs] );
					topQueriesParsed = true;
				}
				else
				{
					fileName = arguments[iterArgs];
				}
			}
		}
	}
	//Any error while parsing expecially invalid arguments for stol
	catch(...)
	{
		return false;
	}
	
	if( fromTimestamp > toTimestamp || fileName.empty() )
		return false;
	
	return true;
}


TreatmentType ArgumentParser::getType() const
{
	return type;
}

const std::string &ArgumentParser::getFileName() const
{
	return fileName;
}

const size_t &ArgumentParser::getFromTimestamp() const
{
	return fromTimestamp;
}

const size_t &ArgumentParser::getToTimestamp() const
{
	return toTimestamp;
}

const size_t ArgumentParser::getNQueries() const
{
	if( type == top )
		return numberOfTopQueries;
	return 0;
}

void ArgumentParser::PrintHelp()
{
	std::cout << " Invalid Command Line please use as follows \n "\
	"To show number of distinct Queries : distinct [--from TIMESTAMP] [--to TIMESTAMP] input_file \n"\
	"To show top queries : top nb_top_queries [--from TIMESTAMP] [--to TIMESTAMP] input_file\n\n";
}

ArgumentParser::~ArgumentParser()
{
}

