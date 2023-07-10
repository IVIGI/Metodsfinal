
#include <cmath>
#include "stdafx.h"
#include <iostream>
using namespace std;
int main() {
	 setlocale(LC_ALL, "Russian");
	 system("color F0");
    int a, b;
	cout << "”кажите площадь октагона" << endl;
    cin >> a >> b;

    double side = a + b * sqrt(2);
    int integerSide = static_cast<int>(side); //пределение целочисленной переменной integerSide, в которую сохран€етс€ цела€ часть значени€ side с помощью преобразовани€ типов

    if (side - integerSide == 0) {
        cout << "÷ела€ сторона" << " " << 1 << endl;
    } else {
        cout << " Ќе цела€ сторона" << " " << 0 << endl;
    }

	system("pause");

    return 0;
}