#include <iostream>
#include <windows.h>
#include "../MoneyDll2/Money.h"
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    long h1, h2;
    int k1, k2;
    double num;

    cout << "Введіть першу суму (грн коп): ";
    cin >> h1 >> k1;
    Money m1(h1, (unsigned char)k1);

    cout << "Введіть другу суму (грн коп): ";
    cin >> h2 >> k2;
    Money m2(h2, (unsigned char)k2);

    cout << "\n--- Результати ---\n";
    cout << "Перша сума: " << m1.ToString() << endl;
    cout << "Друга сума: " << m2.ToString() << endl;

    Money sum = m1 + m2;
    cout << "Сума: " << sum.ToString() << endl;

    Money diff = m1 - m2;
    cout << "Різниця: " << diff.ToString() << endl;

    cout << "\nВведіть число для множення: ";
    cin >> num;
    Money mul = m1 * num;
    cout << "Результат множення: " << mul.ToString() << endl;

    cout << "\nВведіть число для ділення: ";
    cin >> num;
    Money div = m1 / num;
    cout << "Результат ділення: " << div.ToString() << endl;

    cout << "\nПорівняння сум:\n";
    cout << "m1 == m2: " << (m1 == m2 ? "так" : "ні") << endl;
    cout << "m1 != m2: " << (m1 != m2 ? "так" : "ні") << endl;
    cout << "m1 > m2: " << (m1 > m2 ? "так" : "ні") << endl;
    cout << "m1 < m2: " << (m1 < m2 ? "так" : "ні") << endl;
    cout << "m1 >= m2: " << (m1 >= m2 ? "так" : "ні") << endl;
    cout << "m1 <= m2: " << (m1 <= m2 ? "так" : "ні") << endl;

    return 0;
}
