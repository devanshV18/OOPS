#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    string name;
    float *cgpaPtr;

    Student(string name, double cgpa){
         this->name = name;
         cgpaPtr = new float; //we created a dynamic memory allocated at runtime of type float to which out float type pointer cgpaPtr points.
         *cgpaPtr = cgpa; //*cgpaPtr => value at the address og cgpaPtr (dereferencing) = cgpa (parameter).
    }


    //MPLEMENTING DEEP COPY
    Student(Student &orgObj){
        this->name = orgObj.name;
        this->cgpaPtr = new float; //allocating new memory 
        *cgpaPtr = *orgObj.cgpaPtr; //allocating same value og orig object at the address of newly allocated memory
    }

    void getinfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;  //printing the dereferenced value at the address of cgpaPtr.
    }
};


int main(){
    //creating an obj s1
    Student s1("Rahul Kumar", 9.1);

    // Copying s1 in s2 -> values get copied to new dynamic memory allocation for s2 as we are implementing deep copy.
    Student s2(s1);
    
    // printing s1 and s2 after copying -> same value but different memory addresses
    s1.getinfo();
    s2.getinfo();


    //lets change cgpa of s2 and name of s2
    *(s2.cgpaPtr) = 9.5;
    s2.name = "Neha Singh";


    // printing s1 and s2 again after making changes at s2.
    s1.getinfo();
    s2.getinfo();
 
    // vvi ->
    // when we cahnged cgpa at s2 and name at s3 it changes cgpa and name of s2 at the memory address allocated to s2. Thus s1 stays unchanged.
    //this happened because of Deep copy s2 created out of s1. -> ref notes
}