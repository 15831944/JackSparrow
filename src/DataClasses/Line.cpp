#include "DataClasses/Line.h"

//////////////////////////////////////////////////////////////////////////
dxf::Line::Line( Point::SPtr p1, Point::SPtr p2 ):Point1(p1), Point2(p2)
{
}

dxf::Line::Line():Point1(NULL), Point2(NULL)
{

}

dxf::Line::~Line()
{
	Point1 = NULL;
	Point2 = NULL;
}

eEntityType dxf::Line::GetType() const
{
	return DXF_LINE;
}

