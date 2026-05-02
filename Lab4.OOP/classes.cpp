#include "classes.h"
#include <utility>
#include <typeinfo>

Employee::Employee()
    : name("Unknown"), experience(0), department("Unknown") {}

Employee::Employee(std::string name, int experience, std::string department)
    : name(std::move(name)), experience(experience),
      department(std::move(department)) {}

Employee::Employee(const Employee& other)
    : name(other.name), experience(other.experience),
      department(other.department) {}

void Employee::setName(std::string n)       { name       = std::move(n); }
void Employee::setExperience(int e)         { experience = e; }
void Employee::setDepartment(std::string d) { department = std::move(d); }

Worker::Worker()
    : Employee(), profession("Unknown") {}

Worker::Worker(std::string name, int experience, std::string department,
               std::string profession)
    : Employee(std::move(name), experience, std::move(department)),
      profession(std::move(profession)) {}

Worker::Worker(const Worker& other)
    : Employee(other), profession(other.profession) {}

void Worker::setProfession(std::string p) { profession = std::move(p); }

void Worker::show() const {
    std::cout << "┌─ Робітник ─────────────────────────────\n"
              << "│  Ім'я:        " << name       << '\n'
              << "│  Підрозділ:   " << department << '\n'
              << "│  Стаж:        " << experience << " р.\n"
              << "│  Професія:    " << profession << '\n'
              << "└────────────────────────────────────────\n";
}

Engineer::Engineer()
    : Employee(), specialization("Unknown"), salary(0.0) {}

Engineer::Engineer(std::string name, int experience, std::string department,
                   std::string specialization, double salary)
    : Employee(std::move(name), experience, std::move(department)),
      specialization(std::move(specialization)), salary(salary) {}

Engineer::Engineer(const Engineer& other)
    : Employee(other), specialization(other.specialization),
      salary(other.salary) {}

void Engineer::setSpecialization(std::string s) { specialization = std::move(s); }
void Engineer::setSalary(double s)              { salary = s; }

void Engineer::show() const {
    std::cout << "┌─ Інженер ──────────────────────────────\n"
              << "│  Ім'я:           " << name           << '\n'
              << "│  Підрозділ:      " << department     << '\n'
              << "│  Стаж:           " << experience     << " р.\n"
              << "│  Спеціалізація:  " << specialization << '\n'
              << "│  Зарплата:       " << salary         << " грн\n"
              << "└────────────────────────────────────────\n";
}

SeniorEngineer::SeniorEngineer()
    : Engineer(), project("Unknown"), teamSize(0) {}

SeniorEngineer::SeniorEngineer(std::string name, int experience,
                                std::string department,
                                std::string specialization, double salary,
                                std::string project, int teamSize)
    : Engineer(std::move(name), experience, std::move(department),
               std::move(specialization), salary),
      project(std::move(project)), teamSize(teamSize) {}

SeniorEngineer::SeniorEngineer(const SeniorEngineer& other)
    : Engineer(other), project(other.project), teamSize(other.teamSize) {}

void SeniorEngineer::setProject(std::string p) { project  = std::move(p); }
void SeniorEngineer::setTeamSize(int t)        { teamSize = t; }

void SeniorEngineer::show() const {
    std::cout << "┌─ Старший інженер ──────────────────────\n"
              << "│  Ім'я:           " << name           << '\n'
              << "│  Підрозділ:      " << department     << '\n'
              << "│  Стаж:           " << experience     << " р.\n"
              << "│  Спеціалізація:  " << specialization << '\n'
              << "│  Зарплата:       " << salary         << " грн\n"
              << "│  Проєкт:         " << project        << '\n'
              << "│  Розмір команди: " << teamSize       << " осіб\n"
              << "└────────────────────────────────────────\n";
}

List::List()
    : name("Unknown"), head(nullptr), tail(nullptr) {}

List::List(std::string name)
    : name(std::move(name)), head(nullptr), tail(nullptr) {}

List::~List() {
    tItem* p = head;
    while (p) {
        tItem* tmp = p->next;
        delete p;
        p = tmp;
    }
}

void List::insert(tObject* obj) {
    tItem* node = new tItem{ obj, nullptr };
    if (!tail) {
        head = tail = node;
    } else {
        tail->next = node;
        tail       = node;
    }
}

Department::Department()              : List()             {}
Department::Department(std::string n) : List(std::move(n)) {}

void Department::forEach(PF action, const std::string& deptName, int& counter) {
    for (tItem* p = head; p; p = p->next)
        action(p->obj, deptName, counter);
}

void Department::show() const {
    std::cout << "\n  ╔══ Підрозділ: " << name << "\n";
    if (!head) {
        std::cout << "  ║  (порожній підрозділ)\n";
    } else {
        for (tItem* p = head; p; p = p->next)
            p->obj->show();
    }
    std::cout << "  ╚══════════════════════════════════════\n";
}

Enterprise::Enterprise()              : List()             {}
Enterprise::Enterprise(std::string n) : List(std::move(n)) {}

void Enterprise::show() const {
    std::cout << "\n╔═══════════════════════════════════════════\n"
              << "║  Підприємство: " << name << "\n"
              << "╠═══════════════════════════════════════════\n";
    for (tItem* p = head; p; p = p->next)
        p->obj->show();
    std::cout << "╚═══════════════════════════════════════════\n";
}

int Enterprise::countEngineersInDepartment(const std::string& deptName) {
    int counter = 0;
    for (tItem* p = head; p; p = p->next) {
        Department* dept = dynamic_cast<Department*>(p->obj);
        if (dept) dept->forEach(countEngineers, deptName, counter);
    }
    return counter;
}

void countEngineers(tObject* obj, const std::string& deptName, int& counter) {
    Engineer* eng = dynamic_cast<Engineer*>(obj);
    if (eng && eng->getDepartment() == deptName) {
        std::cout << "    [+] " << eng->getRole() << ": " << eng->getName() << '\n';
        ++counter;
    }
}