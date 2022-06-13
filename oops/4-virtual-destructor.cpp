#include<iostream>
using namespace std;
class Base {
public:
    Base() {
        cout << "BASE:Constructor.\n";
    }
    // without virtual Derived destructor will not be called;
    virtual void msg() {
        cout << "Base msg\n";
    }
    virtual ~Base() {
        cout << "BASE:Destructor.\n";
    }
};
class Derived : public Base {
public:
    Derived() {
        cout << "Derived:Constructor.\n";
    }
    virtual void msg() {
        cout << "Derived msg\n";
    }
    void msg1() {
        cout << "Derived msg1 non-virtual\n";
    }
    ~Derived() {
        cout << "Derived:Destructor.\n";
    }
};
int main() {
    Base* b = new Derived();
    b->msg();
    // b->msg1();// class base has no member msg1:ERROR
    delete b;
    return 0;
}

// constructor can not be made virtual as they intitialize vptr and vtable;
// each class has vptr and vtable inherited from parent with updated pointers
// to overloaded functions.
// IRRESPECTIVE of weather the class has virtual function or not;
// it wont call derived destructor till based destructor made virtual;

// Without virtual base destructor
// BASE:Constructor.
// Derived:Constructor.
// Derived msg
// BASE:Destructor.
// ***********************
// With virtual base destructor
// BASE:Constructor.
// Derived:Constructor.
// Derived msg
// Derived:Destructor.
// BASE:Destructor.

// NOTE: c = (a++)++; is not valid; lvalue not defined;