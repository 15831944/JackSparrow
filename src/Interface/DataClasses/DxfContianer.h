#pragma once

#include "DXFExpo.h"
#include "DataHeaders.h"
#include "Layer.h"

//////////////////////////////////////////////////////////////////////////
namespace dxf 
{
	class DxfContianer
	{
	public:
		Layer::List m_LayerList;

	public:
		/**
			DxfContianer: Constructor
		*/
		DxfContianer(void);

		/**
			~DxfContianer: Destructor
		*/
		~DxfContianer(void);

	private:
		/**
			DxfContianer: Copy Constructor
		*/
		DxfContianer (const DxfContianer& iRef);

		/**
			Operator =: Assignment Operator
		*/
		DxfContianer& operator = (const DxfContianer& iRhs);
	};
}
