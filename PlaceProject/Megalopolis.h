#ifndef MEGALOPOLIS_H
#define MEGALOPOLIS_H

#include <string>

#include "City.h"

// Клас Megalopolis — мегаполіс, публічно успадковується від City
class Megalopolis : public City {
private:
    // Кількість районів
    int districts;
    // Статус ("Столиця" або "Мегаполіс")
    std::string status;

public:
    // Конструктор за замовчуванням
    Megalopolis();

    // Параметризований конструктор
    Megalopolis(std::string name,
                std::string country,
                double area,
                int population,
                std::string mayor,
                int founded,
                int districts,
                std::string status);

    // Конструктор копіювання
    Megalopolis(const Megalopolis&);

    // Віртуальний деструктор
    virtual ~Megalopolis();

    // Геттери/сеттери для районів та статусу
    int getDistricts() const;
    void setDistricts(int districts);

    std::string getStatus() const;
    void setStatus(std::string status);

    // НЕвіртуальний метод (перевизначення для порівняння з show())
    void info() { std::cout << "Тип: Мегаполіс (Megalopolis)" << std::endl; }

    // Показати інформацію про мегаполіс
    void show() const override;
};

#endif

