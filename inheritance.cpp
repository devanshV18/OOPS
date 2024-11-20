#include<iostream>
#include<string>
using namespace std;



//ENTIRE INHERITANCE CONCEPT WITH PARAMETERISED AND NON PARAMETERISED CONSTRUCTORS FOR PARENT AND CHILD CLASS


class Person {
    public:
    string name;
    int age;

    //PARAMETERISED CONSTRUCTOR PERSON CLASS

    Person(string name, int age){
        cout << "Parameterised Constructor of Person Class" << endl;
        this->name = name;
        this->age = age;
    }

    //NON PARAMETERISED CONSTRUCTOR PERSON CLASS
    
    Person() {
        cout << "non parameterised constructot of Person class" << endl;
    }
};


//Derived class -> inheriting age and name from person class and add roll no new to student class

class Student : public Person { //this simply means that we want to inherit the property from person class in public mode
    public:
    int rollno;

    // NON PARAMETERISED CONSTRUCTOR CHILD CLASS
    
    Student(){
        cout <<"Non Parameterised constructor of Student class" << endl;
    }

    //PARAMETERISED CONSTRUCTOR OF STUDENT CLASS


    //calls person class constructor before the student constructor with name and age.
    Student(string name, int age, int rollno) : Person(name, age){
        cout << "Parametrised constructor of Student class" << endl;
        this->rollno = rollno;
    }
    
    void getInfo(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }
};


int main(){
    //set 1
    // Person p1;

    //set2
    // Student s1;

    //set3

    Student s2("Devansh Verma", 21, 2345);
    s2.getInfo();

}