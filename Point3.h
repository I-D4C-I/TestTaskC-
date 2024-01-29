#pragma once
#include <iostream>

namespace curves {

	class Point3
	{
	private:
		double _x;
		double _y;
		double _z;

	public:
		Point3(double x, double y, double z) : _x(x), _y(y), _z(z) {};
		Point3(const Point3 &point) = default;
		double getX() noexcept;
		double getY() noexcept;
		double getZ() noexcept;
		Point3 withZ(double) noexcept;

		friend std::ostream& operator <<(std::ostream&, const Point3&);

		~Point3() = default;


	};
}

