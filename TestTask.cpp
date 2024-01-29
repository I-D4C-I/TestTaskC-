
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <random>
#include <functional>

#include "CurvesLib.h"

using namespace std;
using namespace curves;


    using Curves = vector<shared_ptr<CurveBase>>;
    using Circles = vector<shared_ptr<Circle>>;

Curves generateCurves(int count) {
    default_random_engine generator;
    uniform_int_distribution<int> distributionShape(0, 2);
    uniform_real_distribution<double> distributionPar(0.1, 42.);
    auto shape = bind(distributionShape, generator);
    auto parameter = bind(distributionPar, generator);


    Curves curves;
    curves.reserve(count);

    for (int i = 0; i < count; i++) {
        switch (shape())
        {
        case 0:
            curves.push_back(make_shared<Ellipse>(parameter(), parameter()));
            break;
        case 1:
            curves.push_back(make_shared<Circle>(parameter()));
            break;
        case 2:
            curves.push_back(make_shared<Spiral>(parameter(), parameter()));
            break;
        default:
            break;
        }
    }

    return curves;

}

Circles getCircles(Curves curves) 
{
    Circles circles;
    circles.reserve(size(curves));

    for (auto& curve : curves) {
        if (auto&& circle = std::dynamic_pointer_cast<curves::Circle>(curve)){
            circles.emplace_back(circle);
        }
    }

    return circles;
}


Circles sortCircles(Circles circles) {
    sort(circles.begin(), circles.end(), [](auto& c1, auto& c2) {
        return c1->getRadius() < c2->getRadius();
        });

    return circles;
}

double calculateTotalRadius(Circles circles) {
    double totalRadius = 0.0;
    
    for (auto& circle : circles) {
        totalRadius += circle->getRadius();
    }
    return totalRadius;
}

int main()
{
    cout << "Hello World!\n";

    const int size = 100;    

    // Заполнение контейнера случайно созданными объектами кривых
    Curves curves = generateCurves(size);
    // Вывод координат точек и производных всех кривых при t = PI/4
    constexpr double t = M_PI / 4.0;

	for (auto& curve : curves) {
		cout << curve->toString()
			<< " point = " << curve->getPoint(t)
			<< "; derivative = " << curve->getDerivative(t)
			<< std::endl;
	}

	std::cout << std::endl;

    // Заполнение второго контейнера только окружностями из первого контейнера
    // Сортировка второго контейнера в порядке возрастания радиусов окружностей
    Circles circles = getCircles(curves);

    circles = sortCircles(circles);

    // Вывод радиусов окружностей из второго контейнера
    for (auto& circle : circles) {
        cout << circle->toString()
            << " point = " << circle->getPoint(t)
            << "; derivative = " << circle->getDerivative(t)
            << std::endl;
    }

    //Вычисление общей суммы радиусов всех кривых во втором контейнере.
    cout << "Total radius of circles: " << calculateTotalRadius(circles) << std::endl;

    return 0;
}


