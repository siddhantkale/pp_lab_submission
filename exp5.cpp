#include <iostream>
 #include <stdexcept>
 class Person {
 protected:
    std::string name;
 public:
    Person() : name("") {}
    virtual void input() {
        std::cout << "Enter name: ";
        std::cin >> name;
    }
    virtual void display() {
        std::cout << "Name: " << name << std::endl;
    }
 };
 class Employee : public Person {
 protected:
    int age;
 public:
    Employee() : age(0) {}
    void input() override {
        Person::input();  // Call base class input function
        std::cout << "Enter age: ";
        std::cin >> age;
        if (age < 0) {
            throw std::invalid_argument("Age cannot be negative");
        }
    }
    void display() override {
        Person::display();  // Call base class display function
        std::cout << "Age: " << age << std::endl;
    }
 };
 class Salary {
 protected:
    double salary;
 public:
    Salary() : salary(0.0) {}
    void input() {
        std::cout << "Enter salary: ";
        std::cin >> salary;
        if (salary < 0) {
            throw std::invalid_argument("Salary cannot be negative");
        }
    }
    void display() {
        std::cout << "Salary: $" << salary << std::endl;
    }
 };
 class EmployeeSalary : public Employee, public Salary {
public:
    void input() override {
        Employee::input();  // Call Employee class input function
        Salary::input();    // Call Salary class input function
    }
    void display() override {
        Employee::display();  // Call Employee class display function
        Salary::display();    // Call Salary class display function
    }
 };
 int main() {
    try {
        const int numEmployees = 5;
        EmployeeSalary employees[numEmployees];
        for (int i = 0; i < numEmployees; ++i) {
            std::cout << "\nEnter details for employee " << i + 1 << ":\n";
            employees[i].input();
        }
        std::cout << "\nEmployee details:\n";
        for (int i = 0; i < numEmployees; ++i) {
            std::cout << "\nDetails for employee " << i + 1 << ":\n";
            employees[i].display();
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
 }
