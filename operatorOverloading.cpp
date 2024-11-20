#include<iostream>
using namespace std;

class Complex{
    public:
        int real;
        int img;

        //CONSTRUCTOR
        Complex(int r, int i){
            this->real = r;
            this->img = i;
        }

        Complex operator+(const Complex &other){
            return Complex( real + other.real, img + other.img );
        }
};

int main(){
    Complex c1(3,4), c2(1,2);
    Complex c3 = c1 + c2;
    cout << c3.real << " + " << c3.img << "i" << endl;
    return 0;
}