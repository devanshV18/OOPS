#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class show function called." << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show function called." << endl;
    }
};

int main() {

    //method oveririding - fails in case of pointer. -> it calls the function based on type of pointer and the type of object it is pointing too.

    Base *bptr; //bptr is a a base class type pointer
    Derived d;  
    bptr = &d; //d is a derived class object to which bptr points

    // This will call Base class show function, not Derived class show function
    bptr->show();  

    //Method overriding -> works fine
    Base b;
    b.show();
    Derived e;
    e.show();

    return 0;
}
