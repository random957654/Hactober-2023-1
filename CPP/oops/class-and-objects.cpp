#include <iostream>

class Rectangle {
public:
    double length;
    double width;

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle rectangle;
    rectangle.length = 5.0;
    rectangle.width = 3.0;

    std::cout << "Area: " << rectangle.area() << std::endl;
    std::cout << "Perimeter: " << rectangle.perimeter() << std::endl;

    return 0;
}