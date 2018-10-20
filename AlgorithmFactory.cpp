#include "AlgorithmFactory.hpp"

#include "DistinctAlgorithm.hpp"
#include "TopAlgorithm.hpp"

using namespace hnStat;

std::unique_ptr<AlgorithmInterface> AlgorithmFactory::GetAlgorithm( const ArgumentParser &parser )
{
	switch(parser.getType())
	{
		case distinct:
			return std::make_unique<DistinctAlgorithm>();
		case top:
			return std::make_unique<TopAlgorithm>( parser.getNQueries() );
		default:
			break;
	}
	return nullptr;
}