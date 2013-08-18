#include "HelperClasses/Helper.h"
#include <algorithm>
using namespace std;

Helper::Helper(void)
{
}


Helper::~Helper(void)
{
}

DXF_DLL_EXPORT std::ostream& operator << (std::ostream& os, const dxf::Point& iPoint)
{
	os << "x : " << std::setprecision(8) << iPoint.x << std::endl;
	os << "y : " << std::setprecision(8) << iPoint.y << std::endl;
	os << "z : " << std::setprecision(8) << iPoint.z << std::endl;

	return os;
}

std::string Helper::Trim( const std::string& iString )
{
	if(iString.empty())
		return std::string();

	std::string whiteSpaces("\t\f\n\r\v ");
	size_t first_pos = iString.find_first_not_of(whiteSpaces);
	size_t last_pos = iString.find_last_not_of(whiteSpaces);

	if(first_pos != string::npos || last_pos != string::npos)
	{
		return iString.substr(first_pos, (last_pos - first_pos) + 1);
	}

	return iString;
}

bool Helper::Compare( const std::string& iString1, const std::string& iString2 )
{
	string trimString1 = Trim(iString1);
	string trimString2 = Trim(iString2);

	if(0 == trimString1.compare(trimString2))
		return true;

	return false;
}

bool Helper::iCompare(const std::string& iString1, const std::string& iString2)
{
	string trimString1 = Trim(iString1);
	string trimString2 = Trim(iString2);
	
	transform(trimString1.begin(), trimString1.end(), trimString1.begin(), ::tolower);
	transform(trimString2.begin(), trimString2.end(), trimString1.begin(), ::tolower);

	if(0 == trimString1.compare(trimString2))
		return true;

	return false;
}

void Helper::SkipLines(ifstream& iFstream, const size_t& numOfLines)
{
	for(size_t index = 0; index < numOfLines; index++)
	{
		string dummy;
		std::getline(iFstream, dummy);
	}
}
