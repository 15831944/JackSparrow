#pragma once

#include "DXFExpo.h"
#include "DataHeaders.h"
#include "Point.h"
#include "IEntity.h"

//////////////////////////////////////////////////////////////////////////
namespace dxf
{
	class DXF_DLL_EXPORT Line : public IEntity
	{
	public:
		typedef std::shared_ptr<Line> SPtr;
		typedef std::vector<Line::SPtr> List;

	public:
		Point::SPtr Point1;
		Point::SPtr Point2;

	public:
		/**
			Line: Parameterized Constructor
		*/
		Line(Point::SPtr p1, Point::SPtr p2);

		/**
			Line: Default Constructor
		*/
		Line();

		/**
			Line: Destructor
		*/
		~Line();

		/**
			GetType: 
		*/
		eEntityType GetType() const;

	private:
		/**
			Line: Copy Constructor made Private to avoid Pass by value
		*/
		Line(const Line& iRefLine);

		/**
			Line: Assignment Operator made Private to avoid any assignment
		*/
		Line& operator = (const Line& rhs);
	};
}