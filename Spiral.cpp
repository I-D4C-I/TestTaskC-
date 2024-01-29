#include "Spiral.h"

namespace curves {

    double Spiral::getRadius() const noexcept
    {
        return _circle.getRadius();
    }
    double Spiral::getStep() const noexcept
    {
        return _step;
    }
    Point3 Spiral::getPoint(double parameter) const noexcept
    {
        return _circle.getPoint(parameter).withZ(_step * parameter / M_2PI);
    }
    Point3 Spiral::getDerivative(double parameter) const noexcept
    {
        return _circle.getDerivative(parameter).withZ(_step / M_2PI);
    }
    std::string Spiral::toString() const noexcept
    {
        return "Spiral ";
    }
}