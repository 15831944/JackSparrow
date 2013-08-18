#pragma once

#include "DataDefines.h"

namespace dxf
{
	class DXF_DLL_EXPORT IEntity
	{
	public:
		typedef std::shared_ptr<IEntity> SPtr;
		typedef std::vector<IEntity::SPtr> List;

	public:
		
		/**
			IEntity: Constructor
		*/
		IEntity(){}

		/**
			~IEntity: Destructor
		*/
		virtual ~IEntity() {};

		/**
			GetType:
		*/
		virtual eEntityType GetType() const = 0;

	private:
		/**
			
		*/
		IEntity(const IEntity& iEntity);

		IEntity& operator = (const IEntity& iEnity);
	};
}