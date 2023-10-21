#include <iostream>

class Shape {
public:
    virtual double area() {
        return 0;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

private:
    double length;
    double width;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

int main() {
    Shape* shape1 = new Rectangle(5.0, 3.0);
    Shape* shape2 = new Circle(2.0);

    std::cout << "Area of Rectangle: " << shape1->area() << std::endl;
    std::cout << "Area of Circle: " << shape2->area() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}