// 03_abstract_factory.cpp
#include <iostream>

using namespace std;

class Computer {
public:
    virtual void print() = 0;
};

class ModernComputer : public Computer {
public:
    void print() override {
        cout << "Modern Computer" << endl;
    }
};

class ClassicComputer : public Computer {
public:
    void print() override {
        cout << "Classic Computer" << endl;
    }
};

class Phone {
public:
    virtual void print() = 0;
};

class ModernPhone : public Phone {
public:
    void print() override {
        cout << "Modern Phone" << endl;
    }
};

class ClassicPhone : public Phone {
public:
    void print() override {
        cout << "Classic Phone" << endl;
    }
};

class Factory {
public:
    virtual Computer* createComputer() = 0;
    virtual Phone* createPhone() = 0;
};

class ModernFactory : public Factory {
public:
    Computer* createComputer() override {
        return new ModernComputer();
    }

    Phone* createPhone() override {
        return new ModernPhone();
    }
};

class ClassicFactory : public Factory {
public:
    Computer* createComputer() override {
        return new ClassicComputer();
    }

    Phone* createPhone() override {
        return new ClassicPhone();
    }
};

int main() {
    Factory* factory = new ModernFactory();
    Computer* computer = factory->createComputer();
    Phone* phone = factory->createPhone();

    computer->print(); // Output: Modern Computer
    phone->print();    // Output: Modern Phone

    factory = new ClassicFactory();
    computer = factory->createComputer();
    phone = factory->createPhone();

    computer->print(); // Output: Classic Computer
    phone->print();    // Output: Classic Phone

    return 0;
}