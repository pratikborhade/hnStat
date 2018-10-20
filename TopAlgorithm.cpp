#include "TopAlgorithm.hpp"
using namespace hnStat;
#include <unordered_map>
#include <algorithm>
#include <iostream>

TopAlgorithm::TopAlgorithm( const std::size_t& topN  ) : topN(topN)
{
}

void TopAlgorithm::Apply( FileStream &fileStream )
{
	using Container = std::unordered_map<std::string,std::size_t>;
	Container map;
	for( auto ite = fileStream.begin(); ite != fileStream.end(); ++ite )
	{
		auto iteMap = map.find( ite->second );
		if( iteMap == map.end() )
		{
			map.insert( std::make_pair( ite->second, 1 ) );
		}
		else
		{
			++iteMap->second;
		}
	}
	using ResType = std::pair< std::string, std::size_t >;
	std::vector< ResType > result ( topN );
	
	auto comparator = []( const Container::value_type& a, const Container::value_type& b )-> bool
	{
		return a.second > b.second;
	};
	
	std::partial_sort_copy( map.begin(), map.end(), result.begin(), result.end(), comparator);
	
	std::for_each( result.begin(), result.end(), []( const Container::value_type &elem ){ std::cout << elem.first << " " << elem.second << "\n";} );
} 

TopAlgorithm::~TopAlgorithm()
{
}

