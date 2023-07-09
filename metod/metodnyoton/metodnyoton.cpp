
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    // Здесь нужно указать  функцию
    return x * x - 4;
}

double derivative(double x) {
    // Здесь нужно указать производную  функции
    return 2 * x;
}

double newton(double x0, double epsilon, int maxIterations) {
    int iteration = 0;
    double x = x0;

    while (abs(func(x)) >= epsilon && iteration < maxIterations) {
        x = x - func(x) / derivative(x);
        iteration++;
    }

    return x;
}

int main() {
	system("color F0");
	setlocale(LC_ALL, "Russian");
    double x0, epsilon;
    int maxIterations;
    cout << "Введите начальное значение x0: ";
    cin >> x0;
    cout << "Введите требуемую точность (epsilon): ";
    cin >> epsilon;
    cout << "Введите максимальное количество итераций: ";
    cin >> maxIterations;

    double root = newton(x0, epsilon, maxIterations);

    if (abs(func(root)) < epsilon) {
        cout << "Корень уравнения: " << root << endl;
    } else {
        cout << "Не удалось найти корень уравнения после " << maxIterations << " итераций." << endl;
    }
	system("pause");

    return 0;
}