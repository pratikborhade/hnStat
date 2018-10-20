#include "DistinctAlgorithm.hpp"

#include <unordered_set>
#include <iostream>

using namespace hnStat;
DistinctAlgorithm::DistinctAlgorithm()
{
}

void DistinctAlgorithm::Apply( FileStream &fileStream )
{
	std::unordered_set<std::string> set;
	
	for( auto ite = fileStream.begin(); ite != fileStream.end(); ++ite )
	{
		set.insert( ite->second );
	}
	std::cout << set.size() << "\n";
}

DistinctAlgorithm::~DistinctAlgorithm()
{
}

