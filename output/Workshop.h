#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <string>

class Workshop {
private:
    std::string name;
    std::string manager;
    int workersCount;

public:
    Workshop();
    Workshop(std::string name, std::string manager, int workersCount);
    Workshop(std::string name);
    Workshop(const Workshop &other);
    ~Workshop();

    std::string getName() const;
    std::string getManager() const;
    int getWorkersCount() const;

    void setName(std::string name);
    void setManager(std::string manager);
    void setWorkersCount(int count);

    std::string toString();
};

#endif