#pragma once
#include "FileStream.hpp"

namespace hnStat
{

class AlgorithmInterface
{
	public:
	virtual void Apply( FileStream &fileStream ) = 0; 
};

}