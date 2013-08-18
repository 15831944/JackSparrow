#include "Dumper.h"
#include "DataClasses/Line.h"
#include "CmdHelper.h"

Dumper::Dumper(void)
{
}


Dumper::~Dumper(void)
{
}

void Dumper::DumpEntities( const dxf::Layer::List& iLayerList, std::ofstream& oFile ) const
{
	size_t numLayers = iLayerList.size();
	oFile << "Number of Layers : " << numLayers << std::endl;
	for(size_t layerIndex = 0; layerIndex < numLayers; layerIndex++)
	{
		dxf::Layer::SPtr pLayer = iLayerList[layerIndex];
		if(NULL == pLayer)
			continue;

		dxf::IEntity::List thisLayerEntities = pLayer->m_EntityList;

		size_t numEntities = thisLayerEntities.size();
		oFile << "Number of Entities : " << numEntities << std::endl;

		for(size_t enityIndex = 0; enityIndex < numEntities; enityIndex++)
		{
			dxf::IEntity::SPtr pEntity = thisLayerEntities[enityIndex];
			if(NULL == pEntity)
				continue;

			if(DXF_LINE == pEntity->GetType())
			{
				oFile << "DXF_LINE : " << enityIndex + 1 << std::endl;
				dxf::Line::SPtr pLine = std::static_pointer_cast<dxf::Line>(pEntity);
				oFile << *pLine << std::endl;
			}
		}
		oFile << std::string(50, '*');
	}
}
