#include <iostream>

#include "ArgumentParser.hpp"
#include "FileStream.hpp"

int main(int argc, char **argv)
{
    hnStat::ArgumentParser parser( argc, argv );
	
	if( parser.Initialize() )
	{
		hnStat::FileStream fs( parser.getFileName(), parser.getFromTimestamp(), parser.getToTimestamp() );
		auto ite = fs.begin();
		if( ite == fs.end() )
		{
			std::cout << "Error processing the file : " << parser.getFileName();
		}
		for( ; ite != fs.end(); ++ite )
		{
			std::cout << ite->first << "  " << ite->second << "\n"; 
		}
	}
	else
	{
		parser.PrintHelp();
	}
	
    return 0;
}
