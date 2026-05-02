#include <iostream>
#include <clocale>
#include <stdexcept>
#include "Matrix.h"

int main() {
    std::setlocale(LC_ALL, "");

    try {
        std::cout << "=== ТЕСТ КЛАСУ Matrix ===\n\n";

        std::cout << "1) Створення матриці A (2x3) і заповнення через A[i][j]\n";
        Matrix A(2, 3);
        for (int i = 0; i < A.rows; ++i) {
            for (int j = 0; j < A.cols; ++j) {
                A[i][j] = (i + 1) * 10 + (j + 1); // 11 12 13 / 21 22 23
            }
        }
        std::cout << "Матриця A:\n";
        A.Print();
        std::cout << "\n";

        std::cout << "2) Створення матриці B (2x3) і присвоєння всіх елементів значенням 5.5 через operator=(double)\n";
        Matrix B(2, 3);
        B = 5.5;
        std::cout << "Матриця B:\n";
        B.Print();
        std::cout << "\n";

        std::cout << "3) Додавання C = A + B (однакові розміри)\n";
        Matrix C = A + B;
        std::cout << "Матриця C:\n";
        C.Print();
        std::cout << "\n";

        std::cout << "4) Перевірка конструктора копіювання: D = C\n";
        Matrix D = C; // copy constructor
        std::cout << "Матриця D (копія C):\n";
        D.Print();
        std::cout << "\n";

        std::cout << "5) Перевірка operator=(Matrix): E = A\n";
        Matrix E;
        E = A;
        std::cout << "Матриця E (після E = A):\n";
        E.Print();
        std::cout << "\n";

        std::cout << "6) Демонстрація незалежності копії: змінюємо A[0][0] = 999\n";
        A[0][0] = 999;
        std::cout << "Матриця A (після зміни):\n";
        A.Print();
        std::cout << "Матриця E (має лишитися без змін):\n";
        E.Print();
        std::cout << "\n";

        std::cout << "7) Ввід матриці з клавіатури через Input()\n";
        std::cout << "Введіть: rows cols, потім rows*cols елементів\n";
        std::cout << "Приклад для 2x2: 2 2 1 2 3 4\n\n";
        Matrix U;
        std::cout << "Ваш ввід: ";
        U.Input();
        std::cout << "\nМатриця U:\n";
        U.Print();
        std::cout << "\n";

        std::cout << "=== Кінець тесту ===\n";
    } catch (const std::exception& ex) {
        std::cerr << "ПОМИЛКА: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}