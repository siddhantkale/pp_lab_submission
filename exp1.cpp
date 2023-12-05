//using exception handling,inheritqance and friend functions
#exp1
 #include <iostream>
 #include <stdexcept>
 class NumberContainer {
 public:
    virtual void addNumber(double number) = 0;
    virtual double calculateAverage() const = 0;
 };
 class NumberAverageCalculator : public NumberContainer {
 private:
    double numbers[5];
    int count;
 public:
    NumberAverageCalculator() : count(0) {}
    void addNumber(double number) override {
        if (count < 5) {
            numbers[count++] = number;
        } else {
            throw std::out_of_range("Exceeded maximum number count");
        }
    }
    double calculateAverage() const override {
        if (count != 5) {
            throw std::domain_error("Must provide exactly 5 numbers");
        }
        double sum = 0.0;
        for (int i = 0; i < count; ++i) {
            sum += numbers[i];
        }
        return sum / count;
    }
 };
 int main() {
    try {
        NumberAverageCalculator calculator;
        // Read 5 numbers from the user
        std::cout << "Enter 5 numbers: ";
        for (int i = 0; i < 5; ++i) {
            double num;
            if (!(std::cin >> num)) {
                throw std::runtime_error("Invalid input");
            }
            calculator.addNumber(num);
        }
        // Calculate and display the average
        std::cout << "Average: " << calculator.calculateAverage() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
 }
