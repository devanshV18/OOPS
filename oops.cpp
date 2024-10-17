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
};


int main(){
    //object creation
    Teacher t1;
    t1.name = "Devansh Verma";
    t1.dept = "CSE";
    t1.subject = "Backend - Nodejs";
    // t1.salary = 90000 ; //a pvt member, cant be accessed.

    cout << t1.name << " " << t1.dept << " " << t1.subject << endl;
}