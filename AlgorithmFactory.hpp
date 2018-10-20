#pragma once
#include "Common.h"
#include "AlgorithmInterface.hpp"
#include "ArgumentParser.hpp"
#include <memory>
namespace hnStat
{

class AlgorithmFactory
{
	public:
	static std::unique_ptr<AlgorithmInterface> GetAlgorithm( const ArgumentParser &parser );
};

}

