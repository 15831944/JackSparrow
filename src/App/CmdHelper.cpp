#include "CmdHelper.h"
#include <iostream>
#include <iomanip>


CmdHelper::CmdHelper(void)
{
}


CmdHelper::~CmdHelper(void)
{
}

bool CmdHelper::ParseCommandLine( int argc, char* argv[], CmdLineParams& oLineParam )
{
	if(argc != 2)
	{
		PrintHelp(argv[0]);
		return false;
	}

	std::string fileName(argv[1]);
	std::string fileExt = fileName.substr(fileName.find_last_of('.') + 1, 3);

	if(fileExt != "dxf")
	{
		std::cout << "Application accepts (.dxf) files only!!!" << std::endl;
		PrintHelp(argv[0]);
		return false;
	}

	oLineParam.m_FileName = fileName;

	return true;
}

void CmdHelper::PrintHelp(const std::string& iAppName)
{
	std::cout << iAppName << " " << "<FileName>" << std::endl;
	std::cout << "<FileName> : " << "Full Path of Dxf File" << std::endl;
}

//////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& os, dxf::Point& iPoint)
{
	os << std::fixed << std::setprecision(8) << iPoint.x << " " << iPoint.y << " " << iPoint.z << std::endl;
	return os;
}

std::ostream& operator << (std::ostream& os, dxf::Line& iLine)
{
	os << "Point 1: " << *iLine.Point1;
	os << "Point 2: " << *iLine.Point2;
	return os;
}