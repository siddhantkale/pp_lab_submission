#include <iostream>
 #include <cmath>
 class Shape {
 public:
    virtual double calculateVolume() const = 0;  // Pure virtual function
 };
 class Cylinder : public Shape {
 private:
    double radius;
    double height;
 public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    double calculateVolume() const override {
        return M_PI * std::pow(radius, 2) * height;
    }
    friend std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder) 
{
        os << "Cylinder - Radius: " << cylinder.radius << ", Height: " << 
cylinder.height;
        return os;
    }
 };
 class Cube : public Shape {
 private:
    double side;
 public:
    Cube(double s) : side(s) {}
    double calculateVolume() const override {
        return std::pow(side, 3);
    }
    friend std::ostream& operator<<(std::ostream& os, const Cube& cube) {
        os << "Cube - Side: " << cube.side;
        return os;
    }
 };
 class Cuboid : public Shape {
 private:
    double length;
    double width;
    double height;
 public:
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}
    double calculateVolume() const override {
        return length * width * height;
    }
    friend std::ostream& operator<<(std::ostream& os, const Cuboid& cuboid) {
        os << "Cuboid - Length: " << cuboid.length << ", Width: " << 
cuboid.width << ", Height: " << cuboid.height;
        return os;
    }
 };
int main() {
    try {
        // Creating objects of derived classes
        Cylinder cylinder(3.0, 5.0);
        Cube cube(4.0);
        Cuboid cuboid(2.0, 3.0, 4.0);
        // Using virtual functions to calculate volumes
        Shape* shapes[] = {&cylinder, &cube, &cuboid};
        for (const auto& shape : shapes) {
            std::cout << "Volume of " << typeid(*shape).name() << ": " << shape
>calculateVolume() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
