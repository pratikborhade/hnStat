#pragma once

#include <fstream>
#include <memory>

namespace hnStat
{

class FileStream
{
	std::string fileName;
	std::size_t fromTimestamp, toTimestamp;
public:
	FileStream( const std::string &fileName, const std::size_t &fromTimestamp, const std::size_t &toTimestamp );
	~FileStream();
	
	//iterator to iterate over file stream;
	struct iterator
	{
		const std::pair<std::size_t, std::string>& operator*() const;
		
		const std::pair<std::size_t, std::string>* operator->() const;
		
		iterator &operator++();
		
		bool operator == (const iterator& other) const;
		
		bool operator != (const iterator& other) const;
		
		
		iterator( const FileStream& fileStream );
		
		private:
		void goToNext();
		
		inline bool satisfiesCondition();
		
		void setEnd();
		
		iterator( std::shared_ptr< std::ifstream >& ifStream, const FileStream& fileStream  );
		
		bool isEnd = false;
		std::pair<std::size_t, std::string> data;
		std::shared_ptr< std::ifstream > fStream;
		const FileStream& fileStream;
		
		friend class FileStream;
	};
	
	FileStream::iterator begin();
	
	FileStream::iterator end();
	
	friend class iterator;
};

}

