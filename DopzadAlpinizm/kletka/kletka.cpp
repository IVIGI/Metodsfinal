
#include <cmath>
#include "stdafx.h"
#include <iostream>
using namespace std;
int main() {
	 setlocale(LC_ALL, "Russian");
	 system("color F0");
    int a, b;
	cout << "������� ������� ��������" << endl;
    cin >> a >> b;

    double side = a + b * sqrt(2);
    int integerSide = static_cast<int>(side); //���������� ������������� ���������� integerSide, � ������� ����������� ����� ����� �������� side � ������� �������������� �����

    if (side - integerSide == 0) {
        cout << "����� �������" << " " << 1 << endl;
    } else {
        cout << " �� ����� �������" << " " << 0 << endl;
    }

	system("pause");

    return 0;
}