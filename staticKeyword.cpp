#include<iostream>
using namespace std;

void fun(){
    int x = 0;
    cout << "x : " << x << endl;
    x++;
}

void fun2(){
    static int x = 0; //initialised only once out of the stack memory and gets incremented every time we call the function. after x is created once it is in the memory for the life time of the program, hence every time we call it x is found and incremented
    cout << "x : " << x << endl;
    x++;
}

//class 

class A{
    public:
        static int x;

        A(){
            this->x = 100;
        }

        void incX(){
            x=x+1;
        }
};





int main(){
    fun();
    fun();
    fun();

    fun2();
    fun2();
    fun2();
  
    A obj1;
    A obj2;

 
    cout << obj1.x << endl;
    cout << obj2.x << endl;
  
    return 0;
}