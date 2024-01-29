#include "Point3.h"

namespace curves {

	double Point3::getX() noexcept
	{
		return _x;
	}
	double Point3::getY() noexcept
	{
		return _y;
	}
	double Point3::getZ() noexcept
	{
		return _z;
	}
	Point3 Point3::withZ(double z) noexcept
	{
		_z = z;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const Point3& point)
	{
		return stream << "Point(" << point._x << "; " << point._y << "; " << point._z << ")";
	}

}