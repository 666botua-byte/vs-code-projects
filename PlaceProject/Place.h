#ifndef PLACE_H
#define PLACE_H

#include <iostream>
#include <string>

// Попереднє оголошення, щоб можна було створити extern-масив вказівників.
class Place;

// Максимальний розмір колекції
const int MAXSIZE = 100;

// Глобальна поліморфна колекція (масив вказівників на базовий клас).
// Тут зберігаються адреси об'єктів різних похідних класів (Region/City/Megalopolis).
extern Place* collection[MAXSIZE];

// Абстрактний базовий клас Place (ЛР №3: наслідування і поліморфізм)
class Place {
protected:
    // Назва місця
    std::string name;
    // Країна
    std::string country;

public:
    // Лічильник створених об'єктів (індекс останнього доданого в колекцію).
    // static означає, що змінна спільна для всіх об'єктів класу.
    static int count;

    // Перегляд колекції через клас: Place::printAll()
    static void printAll();

    // Конструктор за замовчуванням (збільшує count)
    Place();

    // Параметризований конструктор (збільшує count)
    Place(std::string name, std::string country);

    // Конструктор копіювання
    Place(const Place& other);

    // Віртуальний деструктор потрібен для коректного знищення через вказівник на базовий клас
    virtual ~Place();

    // Сеттери/геттери
    void setName(std::string name);
    void setCountry(std::string country);
    std::string getName() const;
    std::string getCountry() const;

    // Додає поточний об'єкт у колекцію.
    // this — вказівник на поточний об'єкт.
    void add(); // collection[count] = this

    // НЕвіртуальний метод для порівняння з virtual show()
    void info() { std::cout << "Тип: Місце (базовий клас)" << std::endl; }

    // Чисто віртуальний метод — робить клас Place абстрактним.
    // Похідні класи зобов'язані реалізувати show().
    virtual void show() const = 0;
};

#endif
