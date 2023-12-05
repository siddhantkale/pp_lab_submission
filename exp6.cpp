#include <iostream>
 #include <stdexcept>
 class ClassB;  // Forward declaration
 class ClassA {
 private:
    int dataA;
 public:
    ClassA() : dataA(0) {}
    virtual void inputData() {
        std::cout << "Enter data for ClassA: ";
        std::cin >> dataA;
        if (dataA < 0) {
            throw std::invalid_argument("Data cannot be negative");
        }
    }
    virtual void displayData() {
        std::cout << "Data in ClassA: " << dataA << std::endl;
    }
    friend void swapData(ClassA& objA, ClassB& objB);  // Friend function 
declaration
 };
 class ClassB : public ClassA {
 private:
    int dataB;
 public:
    ClassB() : dataB(0) {}
    void inputData() override {
        ClassA::inputData();  // Call base class input function
        std::cout << "Enter data for ClassB: ";
        std::cin >> dataB;
        if (dataB < 0) {
            throw std::invalid_argument("Data cannot be negative");
        }
    }
    void displayData() override {
        ClassA::displayData();  // Call base class display function
        std::cout << "Data in ClassB: " << dataB << std::endl;
    }
    friend void swapData(ClassA& objA, ClassB& objB);  // Friend function 
declaration
 };
 // Friend function definition
 void swapData(ClassA& objA, ClassB& objB) {
    try {
        // Swap private data members
        int temp = objA.dataA;
        objA.dataA = objB.dataB;
        objB.dataB = temp;
    } catch (const std::exception& e) {
        std::cerr << "Error in swapping data: " << e.what() << std::endl;
}
    }
 int main() {
    try {
        ClassA objA;
        ClassB objB;
        std::cout << "Enter data for ClassA and ClassB:\n";
        objA.inputData();
        objB.inputData();
        std::cout << "\nBefore swapping:\n";
        objA.displayData();
        objB.displayData();
        // Swap data using friend function
        swapData(objA, objB);
        std::cout << "\nAfter swapping:\n";
        objA.displayData();
        objB.displayData();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
 }
