#include<iostream>
using namespace std;
// abstract or abstract base class;
// its object can;t be created;
// class having pure virtual function is known as abstract class
class A {
public:
    // pure virtual function
    virtual void PURE() = 0;
    A() {
        cout << "A\n";
    }
};
// if sub class does not implement pure virtual function then it is also 
// abstact class;
class B : public A {
public:
    B() {
        cout << "B\n";
    }
};
class C: public B{
    public:
    void PURE(){
        cout<<"I am defined in C; hence i am not abstract class\n";
    }
};

int main() {
    // A* a = new B(); // compile time error;
    A* a = new C();
    a->PURE();
    C c;
    c.PURE();
    a = &c;
    a->PURE();
    // A a; // abstract class object can;t be created; compile time error;
    return 0;
}

// abstract class object can;t be created but pointer can be created;