#include <iostream>

class Shape {
public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

protected:
    double length;
    double width;
};

class Rectangle : public Shape {
public:
    double area() {
        return length * width;
    }
};

int main() {
    Rectangle rectangle;
    rectangle.setDimensions(5.0, 3.0);

    std::cout << "Area: " << rectangle.area() << std::endl;

    return 0;
}