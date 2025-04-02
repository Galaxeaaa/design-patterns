// 02_factory_method.cpp
# include <iostream>

using namespace std;

class Shape {
public:
    virtual void printType() = 0;
};

class Circle: public Shape {
public:
    Circle() {}
    void printType() {
        cout << "Circle" << endl;
    }
};

class Square: public Shape {
public:
    Square() {}
    void printType() {
        cout << "Square" << endl;
    }
};

class ShapeFactory {
public:
    virtual Shape *produce() = 0;
};

class CircleFactory: public ShapeFactory {
public:
    Shape *produce() {
        return new Circle();
    }
};

class SquareFactory: public ShapeFactory {
public:
    Square *produce() {
        return new Square();
    }
};

int main() {
    ShapeFactory *factory = new CircleFactory();
    Shape *shape = factory->produce();
    shape->printType(); // Should print: Circle

    factory = new SquareFactory();
    shape = factory->produce();
    shape->printType(); // Should print: Square
    
    return 0;
}

