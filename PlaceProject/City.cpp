#include "City.h"

#include <iostream>

// Конструктор за замовчуванням: викликаємо Region(), задаємо значення за замовчуванням
City::City() : Region(), mayor("Unknown"), founded(0) {}

City::City(std::string name,
           std::string country,
           double area,
           int population,
           std::string mayor,
           int founded)
    : Region(std::move(name), std::move(country), area, population),
      mayor(std::move(mayor)),
      founded(founded) {}

// Конструктор копіювання: копіюємо базову частину і власні поля
City::City(const City& other)
    : Region(other), mayor(other.mayor), founded(other.founded) {}

// Віртуальний деструктор (тіло порожнє)
City::~City() {}

std::string City::getMayor() const {
    return mayor;
}

void City::setMayor(std::string mayor) {
    this->mayor = std::move(mayor);
}

int City::getFounded() const {
    return founded;
}

void City::setFounded(int founded) {
    this->founded = founded;
}

void City::show() const {
    // show() — віртуальний метод, тому при виклику через Place* виконується
    // версія реального (динамічного) типу об'єкта.
    std::cout << "Тип: Місто" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Країна: " << country << std::endl;
    std::cout << "Площа: " << area << " кв. км" << std::endl;
    std::cout << "Населення: " << population << " осіб" << std::endl;
    std::cout << "Мер: " << mayor << std::endl;
    std::cout << "Засновано: " << founded << " р." << std::endl;
}

