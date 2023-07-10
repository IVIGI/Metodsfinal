
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int nextHeight(int X) { // функция которая возвращает следующую высоту вершины 
    if (X % 2 == 0) {
        return X / 2;
    } else {
        return 3 * X + 1;
    }
}

bool isValidHeight(int X) { //функция которая проверяет, что высота вершины не превышает высоту вершины
    return X < 8848;
}

vector<int> calculatePerspectiveHeights(int startHeight) { //фукнция вычисляет список перспективных вершин, 
														  //начиная с заданной начальной высоты. Она использует цикл, пока текущая высота является допустимой
    vector<int> perspectives;
    int currentHeight = startHeight;
    while (isValidHeight(currentHeight)) {
        if (currentHeight == 8848) {
            perspectives.push_back(currentHeight);
            break;
        } else if (currentHeight % 2 == 0) {
            perspectives.push_back(currentHeight);
            currentHeight = nextHeight(currentHeight);
        } else {
            currentHeight = nextHeight(currentHeight);
        }
    }
    return perspectives;
}

int main() {
	 setlocale(LC_ALL, "Russian");
	 system("color F0");
    int startHeight;
    cout << "Введите начальную высоту: ";
    cin >> startHeight;

    vector<int> perspectives = calculatePerspectiveHeights(startHeight); //объявление вектора perspectives и вызов функции calculatePerspectiveHeights с аргументом startHeight, результат которой присваивается вектору perspectives.
    sort(perspectives.begin(), perspectives.end()); //сортировка элементов вектора perspectives в порядке возрастания.

    int i;
    cout << "Введите номер вершины в списке (начиная с 1): ";
    cin >> i;

    if (i <= perspectives.size()) { //проверка, если номер вершины i меньше или равен размеру вектора perspectives.
        cout << "Высота " << i << "-й вершины: " << perspectives[i-1] << endl;
    } else {
        cout << -1 << endl;
    }

	system("pause");

    return 0;
	
}
