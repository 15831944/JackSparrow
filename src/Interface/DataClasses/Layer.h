#pragma once

#include "DXFExpo.h"
#include "DataHeaders.h"
#include "IEntity.h"

namespace dxf
{
	class DXF_DLL_EXPORT Layer
	{
	public:
		typedef std::shared_ptr<Layer> SPtr;
		typedef std::vector<Layer::SPtr> List;

	public:
		IEntity::List m_EntityList;

	public:
		/**
			Layer: Constructor
		*/
		Layer(void);

		/**
			Layer: Constructor
		*/
		Layer(const IEntity::List& iEntityList);

		/**
			~Layer: Destructor
		*/
		~Layer(void);


	};
}