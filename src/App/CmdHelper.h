#pragma once
#include <string>
#include <ostream>
#include "DataClasses/Point.h"
#include "DataClasses/Line.h"

class CmdLineParams
{
public:
	std::string m_FileName;
};

class CmdHelper
{
public:
	CmdHelper(void);
	~CmdHelper(void);

	static bool ParseCommandLine(int argc, char* argv[], CmdLineParams& cmdParams);

	static void PrintHelp(const std::string& iAppName );

	friend std::ostream& operator << (std::ostream& os, dxf::Point& iPoint);

	friend std::ostream& operator << (std::ostream& os, dxf::Line& iLine);

	//friend std::ostream& operator << (std::ostream& os, dxf::Circle);

	//friend std::ostream& operator << (std::ostream& os, dxf::Arc);
};



