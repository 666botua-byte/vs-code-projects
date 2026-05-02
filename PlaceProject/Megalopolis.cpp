#include "Megalopolis.h"

#include <iostream>

// Конструктор за замовчуванням: викликаємо City(), заповнюємо власні поля
Megalopolis::Megalopolis() : City(), districts(0), status("Unknown") {}

Megalopolis::Megalopolis(std::string name,
                         std::string country,
                         double area,
                         int population,
                         std::string mayor,
                         int founded,
                         int districts,
                         std::string status)
    : City(std::move(name),
           std::move(country),
           area,
           population,
           std::move(mayor),
           founded),
      districts(districts),
      status(std::move(status)) {}

// Конструктор копіювання: копіюємо базову частину і власні поля
Megalopolis::Megalopolis(const Megalopolis& other)
    : City(other), districts(other.districts), status(other.status) {}

// Віртуальний деструктор (тіло порожнє)
Megalopolis::~Megalopolis() {}

int Megalopolis::getDistricts() const {
    return districts;
}

void Megalopolis::setDistricts(int districts) {
    this->districts = districts;
}

std::string Megalopolis::getStatus() const {
    return status;
}

void Megalopolis::setStatus(std::string status) {
    this->status = std::move(status);
}

void Megalopolis::show() const {
    // Віртуальний метод show(): викликається поліморфно через Place*.
    std::cout << "Тип: Мегаполіс" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Країна: " << country << std::endl;
    std::cout << "Площа: " << area << " кв. км" << std::endl;
    std::cout << "Населення: " << population << " осіб" << std::endl;
    std::cout << "Мер: " << mayor << std::endl;
    std::cout << "Засновано: " << founded << " р." << std::endl;
    std::cout << "Районів: " << districts << std::endl;
    std::cout << "Статус: " << status << std::endl;
}

