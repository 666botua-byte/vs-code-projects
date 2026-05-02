#ifndef REGION_H
#define REGION_H

#include <string>

#include "Place.h"

// Клас Region — область (регіон), публічно успадковується від Place
class Region : public Place {
protected:
    // Площа (кв. км)
    double area;
    // Населення
    int population;

public:
    // Конструктор за замовчуванням
    Region();

    // Параметризований конструктор
    Region(std::string name, std::string country, double area, int population);

    // Конструктор копіювання
    Region(const Region&);

    // Віртуальний деструктор
    virtual ~Region();

    void setArea(double area);
    double getArea() const;

    void setPopulation(int population);
    int getPopulation() const;

    // НЕвіртуальний метод (перевизначення для порівняння з show())
    void info() { std::cout << "Тип: Область (Region)" << std::endl; }

    // Перевизначення чисто віртуального методу show() з Place (поліморфізм)
    void show() const override;
};

#endif

