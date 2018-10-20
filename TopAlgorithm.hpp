#pragma once
#include "AlgorithmInterface.hpp"
namespace hnStat
{
	
class TopAlgorithm :  public AlgorithmInterface
{
	std::size_t topN;
public:
	TopAlgorithm( const std::size_t& topN  );
	
	virtual void Apply( FileStream &fileStream ) override; 
	
	~TopAlgorithm();

};

}

