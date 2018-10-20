#include "FileStream.hpp"

using namespace hnStat;

FileStream::FileStream(const std::string &fileName, const std::size_t &fromTimestamp, const std::size_t &toTimestamp)
	: fileName(fileName), fromTimestamp(fromTimestamp), toTimestamp(toTimestamp)
{
}

FileStream::~FileStream()
{
}


FileStream::iterator FileStream::begin()
{
	return iterator(*this);
}

FileStream::iterator FileStream::end()
{
	std::shared_ptr<std::ifstream> nullStream(nullptr);
	return iterator( nullStream, *this );
}



FileStream::iterator::iterator( const FileStream& fileStream )
 : isEnd(false), fStream( new std::ifstream(fileStream.fileName, std::ios::in) ), fileStream(fileStream)
{
	if( !fStream->is_open() )
	{
		setEnd();
		return;
	}
	//forget the first line
	std::getline( *fStream, data.second );
	//get the beginning
	goToNext();
}


FileStream::iterator::iterator( std::shared_ptr< std::ifstream >& ifStream, const FileStream& fileStream  ):
	isEnd(false), fileStream(fileStream), fStream(ifStream)
{
	if( fStream == nullptr || fStream->eof() )
	{
		setEnd();
		return;
	}
	else
	{
		goToNext();
	}
}

void FileStream::iterator::goToNext()
{
	if( fStream->eof() )
	{
		setEnd();
		return;
	}
	while( (*fStream) >> data.first >> data.second && !satisfiesCondition() )
	{
	}
	if( !satisfiesCondition() )
	{
		setEnd();
	}
}

inline bool FileStream::iterator::satisfiesCondition()
{
	if( fileStream.fromTimestamp > 0 && data.first < fileStream.fromTimestamp )
		return false;
	if( fileStream.toTimestamp > 0 && data.first > fileStream.toTimestamp )
		return false;
	return true;
}

void FileStream::iterator::setEnd()
{
	isEnd = true;
	data = std::make_pair(0,"");
}

const std::pair<std::size_t, std::string> &FileStream::iterator::operator*() const
{
	return data;
}

const std::pair<std::size_t, std::string>* FileStream::iterator::operator->() const
{
	return &data;
}

FileStream::iterator &FileStream::iterator::operator++()
{
	goToNext();
	return *this;
}

bool FileStream::iterator::operator == (const iterator& other) const
{
	if( isEnd && other.isEnd)
		return true;
	if( (isEnd && !other.isEnd) || (!isEnd && other.isEnd) )
		return false;
	return data == other.data;
}

bool FileStream::iterator::operator != (const iterator& other) const
{
	return !(operator==(other));
}

