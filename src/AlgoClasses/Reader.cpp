#include "Reader.h"
#include "DataClasses/DataHeaders.h"
#include "HelperClasses/Helper.h"

Reader::Reader(void)
{
}


Reader::~Reader(void)
{
}

bool Reader::ReadDXF( const std::string& iInputFileName, dxf::Layer::List& oLayerList )
{
	//ValidateInputFile
	bool retValue = false;
	std::ifstream fin (iInputFileName.c_str());
	if(false == fin.good())
		return retValue;

	//ParseInputFile
	retValue = ReadDXF(fin, oLayerList);

	return retValue;
}

bool Reader::ReadDXF( std::ifstream& iFile, dxf::Layer::List& oLayerList )
{
	if(false == iFile.good())
		return false;
	
	dxf::IEntity::List entityList;

	bool isInEntitiesSection = false;
	while (false == iFile.eof())
	{
		std::string currentLine;
		std::getline(iFile, currentLine);

		if(!Helper::Compare(currentLine, "ENTITIES"))
			continue;

		//Fetch Layers.

		isInEntitiesSection = true;
		while(isInEntitiesSection && !iFile.eof())
		{
			std::getline(iFile, currentLine);
			if(Helper::Compare(currentLine,"LINE"))
			{
				FetchLineParams(iFile, entityList);
			}
			else if (Helper::Compare(currentLine,"CIRCLE"))
			{
				//FetchCircleParams();
			}
			else if (Helper::Compare(currentLine,"ARC"))
			{
				//FetchArcParams(iStream);
			}
			else if (Helper::Compare(currentLine,"ENDSEC"))
			{
				isInEntitiesSection = false;
			}
		}
	}

	dxf::Layer::SPtr pLayer(new dxf::Layer(entityList));

	oLayerList.push_back(pLayer);
	
	return true;
}

bool Reader::FetchLineParams( std::ifstream& iFile, dxf::IEntity::List& oEntityList )
{
	std::string currentLine;
	std::getline(iFile, currentLine);

	dxf::Point::SPtr point1(new dxf::Point());
	dxf::Point::SPtr point2(new dxf::Point());

	size_t numPoints = 0;
	bool IsLineParamDone = false;
	while((IsLineParamDone == false) && !iFile.eof())
	{
		double lcords = 0.0;
		if(Helper::Compare(currentLine, "10"))
		{
			std::getline(iFile, currentLine);
			point1->x = atof(currentLine.c_str());
			++numPoints;
		}
		else if(Helper::Compare(currentLine, "20"))
		{
			std::getline(iFile, currentLine);
			point1->y = atof(currentLine.c_str());
			++numPoints;
		}
		else if(Helper::Compare(currentLine, "30"))
		{
			std::getline(iFile, currentLine);
			point1->z = atof(currentLine.c_str());
			++numPoints;
		}
		else if(Helper::Compare(currentLine, "11"))
		{
			std::getline(iFile, currentLine);
			point2->x = atof(currentLine.c_str());
			++numPoints;
		}
		else if(Helper::Compare(currentLine, "21"))
		{
			std::getline(iFile, currentLine);
			point2->y = atof(currentLine.c_str());
			++numPoints;

		}
		else if(Helper::Compare(currentLine, "31"))
		{
			std::getline(iFile, currentLine);
			point2->z = atof(currentLine.c_str());
			++numPoints;
		}

		if(numPoints == 6)
			IsLineParamDone = true;

		std::getline(iFile, currentLine);
	}

	if(IsLineParamDone)
	{
		dxf::Line::SPtr pLine(new dxf::Line(point1, point2));
		oEntityList.push_back(pLine);

		return true;
	}
	return false;
}
