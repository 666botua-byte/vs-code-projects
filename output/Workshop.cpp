#include "Workshop.h"
#include <iostream>
#include <sstream>

// Конструктор за замовчуванням
Workshop::Workshop() {
    name = "Невідомий цех";
    manager = "Вакантно";
    workersCount = 0;
    std::cout << "Викликано: Конструктор без параметрів для об'єкта "
              << this << std::endl;
}

// Основний конструктор
Workshop::Workshop(std::string n, std::string m, int w) {
    name = n;
    manager = m;
    workersCount = w;
    std::cout << "Викликано: Конструктор з параметрами для "
              << name << std::endl;
}

// Конструктор приведення типу
Workshop::Workshop(std::string n) {
    name = n;
    manager = "Не призначено";
    workersCount = 0;
    std::cout << "Викликано: Конструктор приведення типу для "
              << name << std::endl;
}

// Конструктор копіювання
Workshop::Workshop(const Workshop &other) {
    name = other.name;
    manager = other.manager;
    workersCount = other.workersCount;
    std::cout << "Викликано: Конструктор копіювання (копія "
              << other.name << ")" << std::endl;
}

// Деструктор
Workshop::~Workshop() {
    std::cout << "Викликано: Деструктор для об'єкта "
              << name << " (" << this << ")" << std::endl;
}

// Getters
std::string Workshop::getName() const { return name; }
std::string Workshop::getManager() const { return manager; }
int Workshop::getWorkersCount() const { return workersCount; }

// Setters
void Workshop::setName(std::string n) { name = n; }
void Workshop::setManager(std::string m) { manager = m; }
void Workshop::setWorkersCount(int w) { workersCount = w; }

// toString
std::string Workshop::toString() {
    std::stringstream ss;
    ss << "Цех: " << name
       << ", Начальник: " << manager
       << ", Працівників: " << workersCount;
    return ss.str();
}
