#include<bits/stdc++.h>
using namespace std;

class student{
    string name;
public:
    int age;
    string gender;

    student(){
        cout<<"Default constructor"<<endl;
    }
    student(string n, int a, string g){
        cout<<"Parameterised constructor"<<endl;
        name = n;
        age = a;
        gender = g;
    }

    student(student &a){
        cout<<"Copy constructor called";
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~student(){
        cout<<"Deconstructor called"<<endl;
    }
    void setname(string n){
        name = n;
    }
    void getname(){
        cout<<name<<endl;
    }
    void getInfo(){
        cout<<"Name: "<<name;
        cout<<"\nAge: "<<age;
        cout<<"\nGender: "<<gender<<endl;
    }

    bool operator == (student &a){
        if(name == a.name && age ==a.age && gender == a.gender)
            return true;
        return false;
    }
};
int main(){
    student a;
    a.setname("shalaka");
    a.getname();
    a.age = 10;
    a.gender = "Female";
    a.getInfo();

    student b("varun", 5, "Male");
    b.getInfo();

    student c = a;
    c.getInfo();
    c.age = 21;
    c.getInfo();
    a.getInfo();
    student d(b);
    d.getInfo();
    // d.age = 50;
    // b.getInfo();
    // d.getInfo();
    if(b == d)
        cout<<"Same"<<endl;
    else
        cout<<"Different"<<endl;
    return 0;
}