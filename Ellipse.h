#pragma once

#include "CurveBase.h"

namespace curves {

    class Ellipse :
        public CurveBase
    {
    private:
        double _xRadius;
        double _yRadius;

    public:
        Ellipse(double, double);
        double getRadiusX() const noexcept;
        double getRadiusY() const noexcept;
        Point3 getPoint(double) const noexcept override;
        Point3 getDerivative(double) const noexcept override;
        std::string toString() const noexcept override;
    };
}

