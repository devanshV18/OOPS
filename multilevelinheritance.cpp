#include<iostream>
#include<string>
using namespace std;



//multilevel inheritance.


class Person {
    public:
    string name;
    int age;

    //PARAMETERISED CONSTRUCTOR PARENT CLASS

    Person(string name, int age){
        this->name = name;
        this->age = age;
        cout << "Person Parameterised Constructor" << endl;

    }

    //NON PARAMETERISED CONSTRUCTOR PARENT CLASS
    
    Person() {
        cout << "Person class non parameterised constructor" << endl;
    }
};


//Derived class -> inheriting age and name from person class and add roll no new to student class

class Student : public Person { //this simply means that we want to inherit the property from person class in public mode
    public:
    int rollno;

    //NON PARAMETERISED CONSTRUCTOR CHILD CLASS
    
    Student(){
        cout <<"Student class Non Parameterised contructor" << endl;
    }

    //PARAMETERISED CONSTRUCTOR OF STUDENT CLASS


    //calls person class constructor before the student constructor with name and age.
    Student(string name, int age, int rollno) : Person(name, age){
        this->rollno = rollno;
        cout << "Student Parameterised Constructor" << endl;

    }
    
    void getInfo(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }
};


class GradStudent : public Student{
    public:
    string researchArea;

    GradStudent(){
        cout <<"Grad Student Non Parameterised constructor"<< endl;
    }


    //we need to chain just two consecutive class contructor with the appropriate parameters.

    //originating class takes in all parametrs and pass the rest two the class jsut above it. the class just above handles rest and so on. 
    GradStudent(string name, int age, int rollno, string researchArea) : Student(name, age, rollno) {
        this->researchArea = researchArea;
        cout << "Grad Student Parameterised Constructor" << endl;
    }

    void getInfoGradStudent(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
        cout << "research Area: " << researchArea << endl;
    }
};


int main(){

    //in case of declaring a gradstudent obj with the empty / default constructor

    // 1.
    // GradStudent g1; 
    //calls the default constructor of person then student and then gradStrudent's constructor gets called

    // 2. including 1
    // g1.name = "Tony";
    // g1.age = 25;
    // g1.rollno = 54;
    // g1.researchArea = "Data analytics";
    // g1.getInfoGradStudent();

    //calling parameterised constructor

    // 3.
    GradStudent g2("Devansh Verma", 21, 22, "Hosting & Deployment Tech");
    g2.getInfoGradStudent();

    return 0;
}