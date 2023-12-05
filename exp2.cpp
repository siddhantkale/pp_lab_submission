#include <iostream>
 #include <stdexcept>
 class PowerBase {
 public:
    virtual double calculatePower(double n, int p) const = 0;
 };
 class PowerIntermediate : public PowerBase {
 protected:
    double calculatePower(double n, int p) const override {
        double result = 1.0;
        for (int i = 0; i < p; ++i) {
            result *= n;
        }
        return result;
    }
 };
 class PowerCalculator : public PowerIntermediate {
 private:
    double result;
 public:
    friend void readInput(PowerCalculator& obj);
    double getResult() const {
        return result;
    }
 };
 void readInput(PowerCalculator& obj) {
    double base;
    int exponent;
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;
    if (exponent < 0) {
        throw std::invalid_argument("Invalid input. Exponent must be a non
negative integer.");
    }
    obj.result = obj.calculatePower(base, exponent);
 }
 int main() {
    try {
        PowerCalculator powerCalculator;
        // Read base and exponent from the user
        readInput(powerCalculator);
        // Display the result
        std::cout << "Result: " << powerCalculator.getResult() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}
    return 0
