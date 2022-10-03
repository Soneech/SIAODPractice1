#include <iostream>
using namespace std;

int const constant = 0x1AFF7;  // 0001 1010 1111 1111 0111

void coutp(unsigned int x) {
    int n = sizeof(int) * 8;
    unsigned maska = (1 << (n - 1));

    for (int i = 1; i <= n; i++) {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    cout << endl;
}

void first() {
    int mask = 0b11100000000000000000;
    coutp(constant | mask);
}

void second(int number) {
    int mask = ~(0b101000000001000);
    coutp(number & mask);
}

void third(int number) {
    int multiplier = 2; // 2^2 = 4
    coutp(number << multiplier);
}

void fourth(int number) {
    int multiplier = 2; // 2^2 = 4
    coutp(number >> multiplier);
}

void fifth() {

}

void input(int& number) {
    cout << "Введите число: ";
    cin >> number;
    cout << "Исходное число:" << endl;
    coutp(number);
    cout << "Результат:" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int task;
    cout << "Введите номер задания:" << endl;
    cin >> task;

    int number;

    switch (task) {
        case 1:
            cout << "Исходное число:" << endl;
            coutp(constant);
            first();
            break;
        case 2:
            input(number);
            second(number);
            break;
        case 3:
            input(number);
            third(number);
            break;
        case 4:
            input(number);
            fourth(number);
            break;
        case 5:
            fifth();
            break;
        default:
            break;
    }
}