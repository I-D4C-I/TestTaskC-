#pragma once
#include <corecrt_math_defines.h>

#include "CurveBase.h"
#include "Circle.h"

namespace curves {


    class Spiral :
        public CurveBase
    {
    private:
        static constexpr double M_2PI = M_PI * 2.;
        Circle _circle;
        double _step;
    public:
        explicit Spiral(double radius, double step) : _circle(radius), _step(step) {};
        double getRadius() const noexcept;
        double getStep() const noexcept;
        Point3 getPoint(double) const noexcept override;
        Point3 getDerivative(double) const noexcept override;
        std::string toString() const noexcept override;
    };
}

