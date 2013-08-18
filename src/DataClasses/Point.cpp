
#include "DataClasses/Point.h"

//////////////////////////////////////////////////////////////////////////

dxf::Point::Point( const double& ix, const double& iy, const double& iz ): x(ix), y(iy), z(iz)
{
}

dxf::Point::Point(): x(0.0), y(0.0), z(0.0)
{
}

dxf::Point::~Point()
{
}

