#include<iostream>
#include<string>
using namespace std;


//CLASS WITH STATIS MEMORY ALLOCATION FOR ALL DATA MEMBERS

// class Student{
//     public:

//     public: string name;
//     double cgpa;

//     //Parameterised Constructor
//     Student(string name, double cgpa){
//         cout << "Parameterised Constructor" << endl;
//         this->name = name;
//         this->cgpa = cgpa;
//     }

//     //Copy Constructor
//     Student(Student &orgObj){
//         this->name = orgObj.name;
//         this->cgpa = orgObj.cgpa;
//     }

//     void getInfo(){
//         cout << "name : " << name << endl;
//         cout << "cgpa : " << cgpa << endl;
//     }

// };

class Student{
public:
    string name;
    float *cgpaPtr;

    Student(string name, double cgpa){
         this->name = name;
         this->cgpaPtr = new float; //we created a dynamic memory allocated at runtime of type float to which out float type pointer cgpaPtr points.
         *(this->cgpaPtr) = cgpa; //*cgpaPtr => value at the address og cgpaPtr (dereferencing) = cgpa (parameter).
    }

    Student(Student &orgObj){
        this->name = orgObj.name;
        this->cgpaPtr = orgObj.cgpaPtr;
    }

    void getinfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;  //printing the dereferenced value at the address of cgpaPtr.
    }
};



int main(){

    //DRIVER CODE FOR OUR CUSTOM CC WITH STATIC MEMORY ALLOCATION FOR ALL DATA MEMBERS, WHICH CREATES A SHALLOW COPY.

    Student s1("Rahul Kumar", 8.9);
    Student s2(s1); //created shallow copy

    cout << "S1" << endl;
    s1.getinfo(); // printing details of S1
    
    cout << "S2" << endl;
    s2.getinfo(); // printing details of S2

    //changing values of object s2.
    s2.name = "Devansh Verma";
    *(s2.cgpaPtr) = 6.8; 

    cout << endl;
    //vvviii
    //this will demonstrate the problem with shallow copy -> name changed only for s2 but cgpa changed for both

    //printing details of s1 and s2 after making changes to s2.
    s1.getinfo();
    s2.getinfo();
}