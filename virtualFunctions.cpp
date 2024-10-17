#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {  // Virtual function
        cout << "Base class show function called." << endl;
    }
};

class Derived : public Base {
public:
    void show() override {  // Override the virtual function
        cout << "Derived class show function called." << endl;
    }
};

int main() {
    // Base *bptr;
    // Derived d;
    // bptr = &d;

    // // This will now call Derived class show function as the function is virtual and overridden in child class, it is called based on the type of object the pointer is pointing to.
    // bptr->show();  

    //direct method overlaoding.-> works fine
    Base b;
    b.show();
    Derived d;
    d.show();

    return 0;
}
