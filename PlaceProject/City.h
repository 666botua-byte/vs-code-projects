#ifndef CITY_H
#define CITY_H

#include <string>

#include "Region.h"

// Клас City — місто, публічно успадковується від Region
class City : public Region {
protected:
    // Мер міста
    std::string mayor;
    // Рік заснування
    int founded;

public:
    // Конструктор за замовчуванням
    City();

    // Параметризований конструктор
    City(std::string name,
         std::string country,
         double area,
         int population,
         std::string mayor,
         int founded);

    // Конструктор копіювання
    City(const City&);

    // Віртуальний деструктор
    virtual ~City();

    // Геттери/сеттери для мера та року заснування
    std::string getMayor() const;
    void setMayor(std::string mayor);

    int getFounded() const;
    void setFounded(int founded);

    // НЕвіртуальний метод (перевизначення для порівняння з show())
    void info() { std::cout << "Тип: Місто (City)" << std::endl; }

    // Перевизначення show() (віртуальний метод) — приклад поліморфізму
    void show() const override;
};

#endif

