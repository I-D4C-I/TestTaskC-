#include <iostream>
#include <cmath>

#include "Ellipse.h"

namespace curves {

	Ellipse::Ellipse(double x_radius, double y_radius) : _xRadius(x_radius), _yRadius(y_radius)
	{
		if (x_radius < 0 || y_radius < 0)
			throw std::runtime_error("Error: Negative radius.");
	}
	double Ellipse::getRadiusX() const noexcept
	{
		return _xRadius;
	}
	double Ellipse::getRadiusY() const noexcept
	{
		return _yRadius;
	}
	Point3 Ellipse::getPoint(double parameter) const noexcept
	{
		return Point3(_xRadius * cos(parameter), _yRadius * sin(parameter), 0.0);
	}

	Point3 Ellipse::getDerivative(double parameter) const noexcept
	{
		return Point3(-_xRadius * sin(parameter), _yRadius * cos(parameter), 0.0);
	}

	std::string Ellipse::toString() const noexcept
	{
		return "Ellipse ";
	}

}