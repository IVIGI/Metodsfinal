#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    //  нужно указать функцию
    return x*x - 4;
}

double bisection(double a, double b, double epsilon) {
    if (func(a) * func(b) >= 0) {
        cout << "Ошибка: функция не удовлетворяет условию f(a) * f(b) < 0" << endl;
        return 0;
    }

    double c;
    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (func(c) == 0.0) {
            break;
		}
        else if (func(c) * func(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return c;
}

int main() {
	system("color F0");
	 setlocale(LC_ALL, "Russian");
    double a, b, epsilon;
   cout << "Введите левую и правую границы интервала: ";
   cin >> a >> b;
   cout << "Введите требуемую точность (epsilon): ";
   cin >> epsilon;

    double root = bisection(a, b, epsilon);
    cout << "Корень уравнения: " << root << endl;

	system("pause");

    return 0;

}
