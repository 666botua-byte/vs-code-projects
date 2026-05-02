#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

class tObject {
public:
    virtual void show() const = 0;
    virtual ~tObject() {}
};
    
class Employee : public tObject {
protected:
    std::string name;
    int         experience;
    std::string department;

public:
    Employee();
    Employee(std::string name, int experience, std::string department);
    Employee(const Employee& other);
    virtual ~Employee() {}

    const std::string& getName()       const { return name; }
    int                getExperience() const { return experience; }
    const std::string& getDepartment() const { return department; }

    void setName(std::string name);
    void setExperience(int experience);
    void setDepartment(std::string department);

    virtual void show()           const = 0;
    virtual std::string getRole() const = 0;
};

class Worker : public Employee {
protected:
    std::string profession;

public:
    Worker();
    Worker(std::string name, int experience, std::string department,
           std::string profession);
    Worker(const Worker& other);
    virtual ~Worker() {}

    const std::string& getProfession() const { return profession; }
    void setProfession(std::string profession);

    std::string getRole() const override { return "Робітник"; }
    void show() const override;
};

class Engineer : public Employee {
protected:
    std::string specialization;
    double      salary;

public:
    Engineer();
    Engineer(std::string name, int experience, std::string department,
             std::string specialization, double salary);
    Engineer(const Engineer& other);
    virtual ~Engineer() {}

    const std::string& getSpecialization() const { return specialization; }
    double             getSalary()         const { return salary; }
    void setSpecialization(std::string specialization);
    void setSalary(double salary);

    std::string getRole() const override { return "Інженер"; }
    void show() const override;
};

class SeniorEngineer : public Engineer {
private:
    std::string project;
    int         teamSize;

public:
    SeniorEngineer();
    SeniorEngineer(std::string name, int experience, std::string department,
                   std::string specialization, double salary,
                   std::string project, int teamSize);
    SeniorEngineer(const SeniorEngineer& other);
    virtual ~SeniorEngineer() {}

    const std::string& getProject()  const { return project; }
    int                getTeamSize() const { return teamSize; }
    void setProject(std::string project);
    void setTeamSize(int teamSize);

    std::string getRole() const override { return "Старший інженер"; }
    void show() const override;
};

struct tItem {
    tObject* obj;
    tItem*   next;
};

typedef void (*PF)(tObject*, const std::string&, int&);

class List : public tObject {
protected:
    std::string name;
    tItem*      head;
    tItem*      tail;

public:
    List();
    explicit List(std::string name);
    virtual ~List();

    const std::string& getName() const { return name; }
    void insert(tObject* obj);
    virtual void show() const = 0;
};

class Department : public List {
public:
    Department();
    explicit Department(std::string name);
    virtual ~Department() {}

    void forEach(PF action, const std::string& deptName, int& counter);
    void show() const override;
};

class Enterprise : public List {
public:
    Enterprise();
    explicit Enterprise(std::string name);
    virtual ~Enterprise() {}

    void show() const override;
    int countEngineersInDepartment(const std::string& deptName);
};

void countEngineers(tObject* obj, const std::string& deptName, int& counter);

#endif // CLASSES_H