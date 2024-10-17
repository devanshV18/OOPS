#include<iostream>
#include<string>
using namespace std;

class Student {
    public: 
        string name;
        int rollno;
};

class Teacher{
    public:
        string subject;
        double salary;
};

class TA : public Student, public Teacher{
    public:
        string status;
};

//can play with constructors and stuff
int main(){
    TA t1;
    t1.name = "Tony STark";
    t1.subject = "DSA";
    t1.rollno = 25;
    t1.salary = 14000;
    t1.status = "Placed";

    cout << t1.name << endl;
    cout << t1.subject << endl;
    cout << t1.rollno << endl;
    cout << t1.salary << endl;
    cout << t1.status << endl;

}