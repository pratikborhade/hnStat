#pragma once

#include "AlgorithmInterface.hpp"
namespace hnStat
{

class DistinctAlgorithm : public AlgorithmInterface
{
public:
	DistinctAlgorithm();
	
	virtual void Apply( FileStream &fileStream ) override; 
	
	~DistinctAlgorithm();

};

}

