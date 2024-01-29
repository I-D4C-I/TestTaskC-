#pragma once
#include "Point3.h"
namespace curves {

	class CurveBase
	{
	public:
		virtual Point3 getPoint(double) const noexcept = 0;
		virtual Point3 getDerivative(double) const noexcept = 0;
		virtual std::string toString() const noexcept { return "CurveBase "; };
		
		virtual ~CurveBase() = default;
	};
}
