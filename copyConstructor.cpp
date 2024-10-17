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


    //CUSTOM CC
    Teacher(Teacher &orgObj){
        cout << "Custom Copy Constructor" << endl;
        this->name = orgObj.name;
        this->salary = orgObj.salary;
        this->dept = orgObj.dept;
        this->subject = orgObj.dept;
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

    // t1.getInfo();
    

    //Default copy Constructor -> invokes when below statement is executed and when we haven't defined our own copy constructor.

    // Teacher t2(t1); //default CC 
    // t2.getInfo(); //print same values for t2 as passed in t1.



    //NOTE -> Default CC creates a shallow copy i.e. it copies all member values from a given object to another object 
    // here all member values of t1 is copied and filled for all member values of object t2.



    //DRIVER CODE FOR OUR CUSTOM CC

    //SINCE WE HAVE CREATED A CUSTOM CC THE CUSTOM CC CALLED IN PLACE OF DEFAULT CC. AND IT WORKS THE SAME. CREATES A SHALLOWCOPY.
    
    
    //VVVI -

    //WE PASS THE OBJECT AS THE ORIGINAL OBJECT BY DOING A PASS BY REFERENCE. IN PASS BY REFERENCE WE PASS THE ADDRESS OF THE OBJECT AND HENCE THE DATA IS REFERENCED OR PICKED FROM THE ACTUAL MEMORY ADDRESS OF THE PASSED OBJECT AND NOT BY A COPY OF PASSED OBJECT AND THE PICKED DATA IS FILLED FOR THE DATA MEMBERS AT THE MEMORY ALLOCATED TO THE NEW OBJ T2 INITIALISED USING THE COPY CONSTRUCTOR.

    
    Teacher t2(t1); 
    t2.getInfo();
}