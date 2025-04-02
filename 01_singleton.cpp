// 01_singleton.cpp
#include <iostream>
#include <map>

using namespace std;

class Cart {
private:    
    Cart() {}
    map<string, int> items;    

public:
    static Cart& getInstance() {
        static Cart instance;
        return instance;
    }

    void addItem(const string& item, int quantity) {
        items[item] += quantity;
    }

    void printItems() {
        cout << "Items in cart:" << endl;
        for (const auto& pair : items) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    Cart& cart = Cart::getInstance();
    cart.addItem("Apple", 2);
    cart.addItem("Banana", 3);
    cart.addItem("Apple", 1); // Adding more apples

    cart.printItems(); // Should print: Apple: 3, Banana: 3

    return 0;
}
