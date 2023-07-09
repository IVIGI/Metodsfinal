
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    // ����� ����� �������  �������
    return x * x - 4;
}

double derivative(double x) {
    // ����� ����� ������� �����������  �������
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
    cout << "������� ��������� �������� x0: ";
    cin >> x0;
    cout << "������� ��������� �������� (epsilon): ";
    cin >> epsilon;
    cout << "������� ������������ ���������� ��������: ";
    cin >> maxIterations;

    double root = newton(x0, epsilon, maxIterations);

    if (abs(func(root)) < epsilon) {
        cout << "������ ���������: " << root << endl;
    } else {
        cout << "�� ������� ����� ������ ��������� ����� " << maxIterations << " ��������." << endl;
    }
	system("pause");

    return 0;
}