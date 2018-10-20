#include <iostream>
#include <fstream>
#include "ArgumentParser.hpp"
#include "FileStream.hpp"
#include "AlgorithmFactory.hpp"

int main(int argc, char **argv)
{
    hnStat::ArgumentParser parser( argc, argv );
	
	if( parser.Initialize() )
	{
		//Check if file exists
		//this part should be replaced with filesystem
		std::ifstream ifs( parser.getFileName(), std::ios::in );
		if( !ifs.is_open() )
		{
			std::cout << "File \"" << parser.getFileName() << "\" Does Not Exist" << "\n";
			return 0;
		}
		ifs.close();
		
		// Algorithm part
		auto algo = hnStat::AlgorithmFactory::GetAlgorithm( parser );
		if( algo == nullptr )
		{
			std::cout << "Alorithm Not Found \n";
			return 0;
		}
		hnStat::FileStream fs( parser.getFileName(), parser.getFromTimestamp(), parser.getToTimestamp() );
		algo->Apply(fs);
	}
	else
	{
		parser.PrintHelp();
	}
	
    return 0;
}
