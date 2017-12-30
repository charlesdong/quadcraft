#include "file.h"
#include <fstream>
using std::ifstream;

const char * readFile(const char * filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
		return nullptr;

	fin.seekg(0, std::ios_base::end);
	int size = fin.tellg();
	fin.seekg(0, std::ios_base::beg);
	// NOTE: on Windows, a newline is counted as 2 chars (\r\n), but
	// when C++ reads the file it will convert \r\n to a single \n
	// so the actual number of chars read is less than 'size'
	// thus we must fill the whole string with NUL
	// or the end of string would be random chars
	char * content = new char[size + 1]{ '\0' };
	fin.read(content, size);
	return content;
}