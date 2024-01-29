#pragma once
#include "Ellipse.h"

namespace curves {

    class Circle :
        public CurveBase
    {
    private:
        const Ellipse _ellipse;

    public:
       explicit Circle(double radius) : _ellipse(radius, radius) {};
       double getRadius() const noexcept;
       Point3 getPoint(double) const noexcept override;
       Point3 getDerivative(double) const noexcept override;
       std::string toString() const noexcept override;
    };
}       
