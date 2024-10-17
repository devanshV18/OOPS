#include<iostream>
#include<string>
using namespace std;



//ENTIRE INHERITANCE CONCEPT WITH PARAMETERISED AND NON PARAMETERISED CONSTRUCTORS FOR PARENT AND CHILD CLASS


class Person {
    public:
    string name;
    int age;

    //PARAMETERISED CONSTRUCTOR PARENT CLASS

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    //NON PARAMETERISED CONSTRUCTOR PARENT CLASS
    
    // Person() {
    //     cout << "Person class non parameterised constructor" << endl;
    // }
};


//Derived class -> inheriting age and name from person class and add roll no new to student class

class Student : public Person { //this simply means that we want to inherit the property from person class in public mode
    public:
    int rollno;

    //NON PARAMETERISED CONSTRUCTOR CHILD CLASS
    
    // Student(){
    //     cout <<"Student class contructor" << endl;
    // }

    //PARAMETERISED CONSTRUCTOR OF STUDENT CLASS


    //calls person class constructor before the student constructor with name and age.
    Student(string name, int age, int rollno) : Person(name, age){
        this->rollno = rollno;
    }
    
    void getInfo(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }
};


int main(){
    Student s1("Rahul", 21, 43);

    s1.getInfo();
    return 0;
}