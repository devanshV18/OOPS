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
         cgpaPtr = new float; //we created a dynamic memory allocated at runtime of type float to which out float type pointer cgpaPtr points.
         *cgpaPtr = cgpa; //*cgpaPtr => value at the address og cgpaPtr (dereferencing) = cgpa (parameter).
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

//     Student s1("Rahul Kumar", 8.9);

//     Student s2(s1);
//     s2.getInfo();


    //DRIVER CODE FOR OUR CC OF THE CLASS WITH DYNAMIC MEMORY ALLOCATION TO THE DATA MEMBER.

    //works fine
    // Student s1("Rahul Kumar", 9.1);

    // Student s2(s1);
    // s2.getinfo();


    //catch -> to understand the problem 

    Student s1("Rahul Kumar", 9.1);

    // Copying s2 in s1
    Student s2(s1);
    
    // printing s1
    s1.getinfo();

    //lets change cgpa of s2
    *(s2.cgpaPtr) = 9.5;

    // printing s1 again
    s1.getinfo();
    s2.getinfo();
    // vvi ->
    // when we cahnged cgpa at s2 it changes cgpa of s1 as well along with s2.
    //this happened because of shallow copy s2 created out of s1. -> ref notes
}