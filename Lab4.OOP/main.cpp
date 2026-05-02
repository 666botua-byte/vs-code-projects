#include <iostream>
#include "classes.h"

// g++ -std=c++11 classes.cpp main.cpp -o lab4

int main() {

    // КРОК 1: Створення співробітників
    Worker         w1("Коваль Петро",       5, "ІТ-відділ",             "Монтажник мереж");
    Engineer       e1("Бондар Олена",       8, "ІТ-відділ",             "Програмна інженерія", 45000.0);
    Engineer       e2("Мельник Іван",       3, "ІТ-відділ",             "Кібербезпека",        38000.0);
    SeniorEngineer se1("Шевченко Тарас",   12, "ІТ-відділ",             "Системна інженерія",  72000.0, "Автоматизація виробництва", 5);

    Worker         w2("Гриценко Юрій",      7, "Конструкторське бюро",  "Слюсар");
    Engineer       e3("Іваненко Світлана",  6, "Конструкторське бюро",  "Механічна інженерія", 42000.0);
    SeniorEngineer se2("Кравченко Олег",   15, "Конструкторське бюро",  "Конструювання",       78000.0, "Новий двигун", 8);

    Worker         w3("Пономаренко Лідія",  4, "Відділ якості",         "Контролер");
    Engineer       e4("Сидоренко Роман",    9, "Відділ якості",         "Інженерія якості",    48000.0);

    // КРОК 2: Побудова ієрархії об'єктів
    Department dept1("ІТ-відділ");
    dept1.insert(&w1);
    dept1.insert(&e1);
    dept1.insert(&e2);
    dept1.insert(&se1);

    Department dept2("Конструкторське бюро");
    dept2.insert(&w2);
    dept2.insert(&e3);
    dept2.insert(&se2);

    Department dept3("Відділ якості");
    dept3.insert(&w3);
    dept3.insert(&e4);

    Enterprise enterprise("ТОВ «Технопром»");
    enterprise.insert(&dept1);
    enterprise.insert(&dept2);
    enterprise.insert(&dept3);

    // КРОК 3: Відображення ієрархії
    enterprise.show();

    // КРОК 4: Метод-ітератор (варіант 19) — кількість інженерів у підрозділі
    std::string targetDept = "ІТ-відділ";
    int counter = 0;

    std::cout << "\nІнженери у підрозділі \"" << targetDept << "\":\n";
    dept1.forEach(countEngineers, targetDept, counter);
    std::cout << ">>> Всього інженерів: " << counter << "\n";

    std::cout << "\n--- Підрахунок через підприємство ---\n";
    for (const std::string& dept : {"ІТ-відділ", "Конструкторське бюро", "Відділ якості"}) {
        int count = enterprise.countEngineersInDepartment(dept);
        std::cout << "\"" << dept << "\": " << count << " інженер(ів)\n";
    }

    int none = enterprise.countEngineersInDepartment("Бухгалтерія");
    std::cout << "\"Бухгалтерія\" (не існує): " << none << " інженер(ів)\n";

    // КРОК 5: RTTI — typeid
    std::cout << "\n--- RTTI (typeid) ---\n";
    tObject* objects[] = { &w1, &e1, &se1 };
    for (tObject* obj : objects)
        std::cout << typeid(*obj).name() << '\n';

    // КРОК 6: Поліморфізм через tObject*
    std::cout << "\n--- Поліморфний виклик show() ---\n";
    tObject* poly = &se1;
    poly->show();

    return 0;
}