#include <iostream>
 #include <string>
 class User {
 protected:
    std::string city;
 public:
    virtual void inputDetails() {
        std::cout << "Enter city: ";
        std::cin >> city;
    }
    virtual void validateDetails() {
        // Validate city
        if (city != "Pune" && city != "Mumbai" && city != "Bangalore" && city !=
 "Chennai") {
            throw std::runtime_error("User must stay in Pune, Mumbai, Bangalore,
 or Chennai.");
        }
    }
    virtual ~User() = default;
 };
 class AgeIncomeUser : public User {
 protected:
    int age;
    double income;
 public:
    void inputDetails() override {
        User::inputDetails();  // Call base class input function
        std::cout << "Enter age: ";
        std::cin >> age;
        if (age < 18 || age > 55) {
            throw std::runtime_error("User age must be between 18 and 55.");
        }
        std::cout << "Enter income: Rs. ";
        std::cin >> income;
        if (income < 50000 || income > 100000) {
            throw std::runtime_error("User income must be between Rs. 50,000 and
 Rs. 1,00,000 per month.");
        }
    }
    void validateDetails() override {
        User::validateDetails();  // Call base class validation function
        // No additional validation needed for AgeIncomeUser
    }
    virtual ~AgeIncomeUser() = default;
 };
 class VehicleUser : public AgeIncomeUser {
 protected:
    bool hasFourWheeler;
 public:
    void inputDetails() override {
        AgeIncomeUser::inputDetails();  // Call base class input function
        std::cout << "Do you have a 4-wheeler? (1 for Yes, 0 for No): ";
        std::cin >> hasFourWheeler;
        if (!hasFourWheeler) {
            throw std::runtime_error("User must have a 4-wheeler vehicle.");
        }
    }
    void validateDetails() override {
        AgeIncomeUser::validateDetails();  // Call base class validation 
function
        // No additional validation needed for VehicleUser
    }
    virtual ~VehicleUser() = default;
 };
 // Function for validation
 void validateUserDetails(User& user) {
    try {
        user.inputDetails();
        user.validateDetails();
        std::cout << "User details are valid.\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
 }
 int main() {
    VehicleUser user;
    validateUserDetails(user);
    return 0;
 }
