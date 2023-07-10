#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


#define MOD 1000000009
using namespace std;
unordered_map<int, int> fib_cache;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (fib_cache.find(n) != fib_cache.end()) {
        return fib_cache[n];
    }

    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }

    fib_cache[n] = b;
    return b;
}

int main() {
	setlocale(LC_ALL, "Russian");
	 system("color F0");
    string mode;
    int num;
    cin >> mode >> num;

    if (mode == "encode") {
        int password = fibonacci(num);
        int key = fibonacci(num * 2);

        cout << (key % MOD) << endl;
    } else if (mode == "decode") {
        int key = num;
        vector<int> fib_numbers;
        fib_numbers.push_back(0);
        fib_numbers.push_back(1);

        int i = 2;
        while (true) {
            int fib_i = fib_numbers[i - 1] + fib_numbers[i - 2];
            fib_numbers.push_back(fib_i);

            if ((key * fib_numbers[i - 1]) % MOD == fib_i) {
                cout << fib_i << endl;
                break;
            }
            i++;
        }
    }

	system("pause");

    return 0;
}