#include "Region.h"

#include <iostream>

// Конструктор за замовчуванням: викликаємо Place(), ініціалізуємо поля області
Region::Region() : Place(), area(0), population(0) {}

// Параметризований конструктор: передаємо name/country у базовий клас Place
Region::Region(std::string name, std::string country, double area, int population)
    : Place(std::move(name), std::move(country)), area(area), population(population) {}

// Конструктор копіювання: копіюємо базову частину і власні поля
Region::Region(const Region& other)
    : Place(other), area(other.area), population(other.population) {}

// Віртуальний деструктор (тіло порожнє)
Region::~Region() {}

double Region::getArea() const {
    return area;
}

void Region::setArea(double area) {
    this->area = area;
}

int Region::getPopulation() const {
    return population;
}

void Region::setPopulation(int population) {
    this->population = population;
}

void Region::show() const {
    // show() — віртуальний метод (оголошений у Place), тому виклик через Place*
    // призведе до виконання версії реального (динамічного) типу об'єкта.
    std::cout << "Тип: Область" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Країна: " << country << std::endl;
    std::cout << "Площа: " << area << " кв. км" << std::endl;
    std::cout << "Населення: " << population << " осіб" << std::endl;
}

