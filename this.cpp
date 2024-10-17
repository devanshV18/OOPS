#include<iostream>
#include<string>
using namespace std;

class Teacher{
    //properties
private:
    double salary;

public:
    string name;
    string dept;
    string subject;


    //constructors : -


    //CONSTRUCTOR 1 -> NON PARAMETERISED

    // Teacher(){
    //     cout << "Hi, This is the Teacher Class" << endl;   
    // }

    //CONSTRUCTOR 2 -> non parameterised

    // Teacher(){
    //     cout << "Hi, This is the Teacher Class, Lets initialise the dept" << endl; 
    //     dept = "Computer Science"; // this constructor automatically assigns dept = computer science whenever an object is created. SO we dont need to assign computer science or a default value to each object upon creation.  
    // }


    //CONSTRUCTOR 3 -> PARAMETERISED CONSTRUCTOR
    Teacher(string name, string dept, string subject, double salary){
        cout << "Hi I am the Parameterised Constructor and assign all values" << endl;
        this->name = name;
        this->dept = dept;
        this->subject = subject,
        this->salary = salary;
    }

    //METHODS
    void changeDept(string newDept){
        dept = newDept;
    }



    //INDIRECT ACCESS TO PRIVATE MEMBER USING GETTERS AND SETTERS

    //SETTER
    void setSalary(double s){
        salary = s;
    }

    //GETTER
    double getSalary(){
        return salary;
    }


    void getInfo(){
        cout << "name : " << name << endl; 
        cout << "subject : " << subject << endl; 
        cout << "separtment : " << dept << endl; 
        cout << "salary : " << salary << endl; 
    }
};


int main(){
    //ALTER MAIN FUNCTION AS PER WHICH CONTRUCTOR IS TO BE CALLED.

    //object creation
    Teacher t1("Devansh Vermna", "CSE", "Backend Nodejs", 90000.00); //calls the constructor -> our defined one , if no contructor defined it calls an internal default constructor triggered by the compiler.
    t1.getInfo();
    // Teacher t2; 

    // t1.name = "Devansh Verma";

    // // t1.dept = "CSE"; 

    // t1.subject = "Backend - Nodejs";


    // cout << t1.name << " " << t1.dept << " " << t1.subject << endl;
}