#include "Place.h"

#include <iostream>

// Глобальна поліморфна колекція.
// Зберігає вказівники на Place, але реально тут можуть бути об'єкти похідних класів
// (Region/City/Megalopolis). Виклик virtual-методу show() буде виконано з динамічним
// зв'язуванням (поліморфізм).
Place* collection[MAXSIZE] = { nullptr };

// Статичний лічильник об'єктів Place (спільний для всіх екземплярів).
int Place::count = -1;

Place::Place() : name("Unknown"), country("Unknown") {
    ++count; // збільшуємо лічильник об'єктів
    collection[count] = this; // автоматичне додавання в колекцію в конструкторі
}

Place::Place(std::string name, std::string country)
    : name(std::move(name)), country(std::move(country)) {
    ++count; // збільшуємо лічильник об'єктів
    collection[count] = this; // автоматичне додавання в колекцію в конструкторі
}

Place::Place(const Place& other)
    : name(other.name), country(other.country) {
    ++count; // копія — це теж новий об'єкт у нашому обліку
    collection[count] = this; // автоматичне додавання в колекцію в конструкторі
}

Place::~Place() = default;

std::string Place::getName() const {
    return name;
}

void Place::setName(std::string name) {
    this->name = std::move(name);
}

std::string Place::getCountry() const {
    return country;
}

void Place::setCountry(std::string country) {
    this->country = std::move(country);
}

void Place::add() {
    // this — вказівник на поточний об'єкт. Додаємо його адресу в глобальну колекцію.
    collection[count] = this;
}

void Place::printAll() {
    // Статичний метод викликається через ім'я класу: Place::printAll().
    std::cout << "=== Перегляд колекції місць (поліморфізм) ===\n";

    for (int i = 0; i <= count; ++i) {
        if (collection[i] != nullptr) {
            // Віртуальний виклик: show() виконується відповідно до РЕАЛЬНОГО типу об'єкта
            // (Region/City/Megalopolis), навіть якщо зберігаємо його як Place*.
            collection[i]->show();
            std::cout << "-------------------------------------------\n";
        }
    }
}
