
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    // Здесь нужно указать вашу функцию
    return x * x - 4;
}

double secant(double x0, double x1, double epsilon, int maxIterations) {
    int iteration = 0;
    double x = x1;

    while (abs(func(x)) >= epsilon && iteration < maxIterations) {
        double denominator = func(x1) - func(x0);
        if (denominator == 0) {
           cout << "Деление на ноль. Метод секущих не может продолжаться." << endl;
            return x;
        }

        double deltaX = func(x1) * (x1 - x0) / denominator;       
        x = x1 - deltaX;
        
        x0 = x1;
        x1 = x;
        iteration++;
    }

    return x;
}

int main() {
	system("color F0");
	 setlocale(LC_ALL, "Russian");
    double x0, x1, epsilon;
    int maxIterations;
    cout << "Введите начальные значения x0 и x1: ";
    cin >> x0 >> x1;
    cout << "Введите требуемую точность (epsilon): ";
    cin >> epsilon;
    cout << "Введите максимальное количество итераций: ";
    cin >> maxIterations;

    double root = secant(x0, x1, epsilon, maxIterations);

    if (abs(func(root)) < epsilon) {
        cout << "Корень уравнения: " << root << endl;
    } else {
        cout << "Не удалось найти корень уравнения после " << maxIterations << " итераций." << endl;
    }
	
	system("pause");

    return 0;
}