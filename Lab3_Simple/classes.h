#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

class Place;

const int MAXSIZE = 100;
extern Place* collection[MAXSIZE];

// Абстрактний базовий клас
class Place {
protected:
    std::string name;
    std::string country;

public:
    static int count;

    Place();
    Place(std::string name, std::string country);
    Place(const Place& other);
    virtual ~Place();

    void setName(std::string name);
    void setCountry(std::string country);
    std::string getName() const;
    std::string getCountry() const;

    // this вказує на поточний об'єкт
    void add();
    static void printAll();

    // НЕ віртуальний метод для порівняння
    void info() { std::cout << "Тип: Місце (базовий клас)" << std::endl; }

    // Чисто віртуальний метод робить Place абстрактним
    virtual void show() const = 0;
};

class Region : public Place {
protected:
    double area;
    int population;

public:
    Region();
    Region(std::string name, std::string country, double area, int population);
    Region(const Region& other);
    virtual ~Region();

    void setArea(double area);
    double getArea() const;
    void setPopulation(int population);
    int getPopulation() const;

    void info() { std::cout << "Тип: Область (Region)" << std::endl; }
    void show() const override;
};

class City : public Region {
protected:
    std::string mayor;
    int founded;

public:
    City();
    City(std::string name, std::string country, double area, int population,
         std::string mayor, int founded);
    City(const City& other);
    virtual ~City();

    void setMayor(std::string mayor);
    std::string getMayor() const;
    void setFounded(int founded);
    int getFounded() const;

    void info() { std::cout << "Тип: Місто (City)" << std::endl; }
    void show() const override;
};

class Megalopolis : public City {
private:
    int districts;
    std::string status;

public:
    Megalopolis();
    Megalopolis(std::string name, std::string country, double area, int population,
                std::string mayor, int founded, int districts, std::string status);
    Megalopolis(const Megalopolis& other);
    virtual ~Megalopolis();

    void setDistricts(int districts);
    int getDistricts() const;
    void setStatus(std::string status);
    std::string getStatus() const;

    void info() { std::cout << "Тип: Мегаполіс (Megalopolis)" << std::endl; }
    void show() const override;
};

#endif

