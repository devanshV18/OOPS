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

    //methods
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
};

int main(){
    //object creation
    Teacher t1;

    //Accessing public members
    t1.name = "Devansh Verma";
    t1.dept = "CSE";
    t1.subject = "Backend - Nodejs";


    //Accessing pvt memebers 
    t1.setSalary(90000.00);
    cout << t1.name << " " << t1.dept << " " << t1.subject << " " << t1.getSalary() << endl;

    // OR
    
//     int sal = t1.getSalary();
//     cout << t1.name << " " << t1.dept << " " << t1.subject << " " << sal << endl;


}