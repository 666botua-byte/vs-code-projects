#include "classes.h"

#include <utility>

Place* collection[MAXSIZE] = {nullptr};
int Place::count = -1;

Place::Place() : name("Unknown"), country("Unknown") {
    ++count;
    collection[count] = this;  // автоматичне додавання
}

Place::Place(std::string name, std::string country)
    : name(std::move(name)), country(std::move(country)) {
    ++count;
    collection[count] = this;  // автоматичне додавання
}

Place::Place(const Place& other) : name(other.name), country(other.country) {
    ++count;
    collection[count] = this;  // автоматичне додавання
}

Place::~Place() {}

void Place::setName(std::string name) { this->name = std::move(name); }
void Place::setCountry(std::string country) { this->country = std::move(country); }
std::string Place::getName() const { return name; }
std::string Place::getCountry() const { return country; }

void Place::add() {
    collection[count] = this;
}

void Place::printAll() {
    std::cout << "=== Перегляд колекції місць (поліморфізм) ===" << std::endl;
    for (int i = 0; i <= count; ++i) {
        if (collection[i] != nullptr) {
            // Віртуальний виклик: виконається show() реального типу об'єкта
            collection[i]->show();
            std::cout << "-------------------------------------------" << std::endl;
        }
    }
}

Region::Region() : Place(), area(0), population(0) {}
Region::Region(std::string name, std::string country, double area, int population)
    : Place(std::move(name), std::move(country)), area(area), population(population) {}
Region::Region(const Region& other) : Place(other), area(other.area), population(other.population) {}
Region::~Region() {}
void Region::setArea(double area) { this->area = area; }
double Region::getArea() const { return area; }
void Region::setPopulation(int population) { this->population = population; }
int Region::getPopulation() const { return population; }
void Region::show() const {
    std::cout << "Тип: Область" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Країна: " << country << std::endl;
    std::cout << "Площа: " << area << " кв. км" << std::endl;
    std::cout << "Населення: " << population << " осіб" << std::endl;
}

City::City() : Region(), mayor("Unknown"), founded(0) {}
City::City(std::string name, std::string country, double area, int population,
           std::string mayor, int founded)
    : Region(std::move(name), std::move(country), area, population),
      mayor(std::move(mayor)), founded(founded) {}
City::City(const City& other) : Region(other), mayor(other.mayor), founded(other.founded) {}
City::~City() {}
void City::setMayor(std::string mayor) { this->mayor = std::move(mayor); }
std::string City::getMayor() const { return mayor; }
void City::setFounded(int founded) { this->founded = founded; }
int City::getFounded() const { return founded; }
void City::show() const {
    std::cout << "Тип: Місто" << std::endl;
    std::cout << "Назва: " << name << std::endl;
    std::cout << "Країна: " << country << std::endl;
    std::cout << "Площа: " << area << " кв. км" << std::endl;
    std::cout << "Населення: " << population << " осіб" << std::endl;
    std::cout << "Мер: " << mayor << std::endl;
    std::cout << "Засновано: " << founded << " р." << std::endl;
}

Megalopolis::Megalopolis() : City(), districts(0), status("Unknown") {}
Megalopolis::Megalopolis(std::string name, std::string country, double area, int population,
                         std::string mayor, int founded, int districts, std::string status)
    : City(std::move(name), std::move(country), area, population, std::move(mayor), founded),
      districts(districts), status(std::move(status)) {}
Megalopolis::Megalopolis(const Megalopolis& other)
    : City(other), districts(other.districts), status(other.status) {}
Megalopolis::~Megalopolis() {}
void Megalopolis::setDistricts(int districts) { this->districts = districts; }
int Megalopolis::getDistricts() const { return districts; }
void Megalopolis::setStatus(std::string status) { this->status = std::move(status); }
std::string Megalopolis::getStatus() const { return status; }
void Megalopolis::show() const {
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

