#include <iostream>
#include <cmath>

#include "Circle.h"

namespace curves {

	Point3 Circle::getPoint(double parameter) const noexcept
	{
		return _ellipse.getPoint(parameter);
	}
	Point3 Circle::getDerivative(double parameter) const noexcept
	{
		return _ellipse.getDerivative(parameter);
	}
	double Circle::getRadius() const noexcept
	{
		return _ellipse.getRadiusX();
	}
	std::string Circle::toString() const noexcept
	{
		return "Circle ";
	}
};
