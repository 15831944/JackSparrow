#pragma once

#include "../DataClasses/DataHeaders.h"
#include "../DataClasses/Point.h"

class DXF_DLL_EXPORT Helper
{
public:

	/**
		Helper: Constructor
	*/
	Helper(void);

	/**
		~Helper: Destructor
	*/
	~Helper(void);

	/**
		std::ostream& operator << : Overloading indirection operator
	*/
	DXF_DLL_EXPORT friend std::ostream& operator << (std::ostream& os, const dxf::Point& iPoint);

	/**
	
	*/
	static std::string Trim(const std::string& iString);

	static bool Compare(const std::string& iString1, const std::string& iString2);

	static bool iCompare(const std::string& iString1, const std::string& iString2);

	static void SkipLines(std::ifstream& iFstream, const size_t& numOfLines);



};

