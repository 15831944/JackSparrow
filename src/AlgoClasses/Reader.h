#pragma once

#include "DataClasses/DXFExpo.h"
#include "DataClasses/Layer.h"
#include "DataClasses/Line.h"

class DXF_DLL_EXPORT Reader
{
public:
	/**
		Reader: Constructor
	*/
	Reader(void);

	/**
		~Reader: Destructor
	*/
	~Reader(void);

	/**
		ReadDXF: 
	*/
	bool ReadDXF(const std::string& iInputFileName, dxf::Layer::List& oLayerList);

	/**
		ReadDXF:
	*/
	bool ReadDXF( std::ifstream& iFile, dxf::Layer::List& oLayerList );

private:

	bool FetchLineParams(std::ifstream& iFile, dxf::IEntity::List& oLineList);

};

