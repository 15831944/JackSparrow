
#pragma once
#include "DXFExpo.h"
#include "DataHeaders.h"

namespace dxf
{
	class DXF_DLL_EXPORT Point
	{
	public:
		typedef std::shared_ptr<Point> SPtr;
		//typedef Point* SPtr;
		typedef std::vector<Point::SPtr> List;

	public:
		double x;
		double y;
		double z;

	public:
		/**
			Point: Parameterized Constructor
			@param: double& 
			@param: double& 
			@param: double& 
		*/
		Point(const double& x, const double& y, const double& z);
		
		/**
			Point: Default Constructor
		*/
		Point();

		/**
			~Point: Destructor
		*/
		~Point();

	};
}

//DXF_DLL_EXPORT std::ostream& operator << (std::ostream& os, const dxf::Point& iPoint);