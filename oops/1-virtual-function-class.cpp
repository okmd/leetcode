#include <iostream>
using namespace std;
class Base {
public:
    //
    virtual void fun() {
        cout << "FUN-BASE: LATE BINDING\n";
    }
    void fun2() {
        cout << "FUN2-BASE: EARLY BINDING\n";
    }
};
class A : public Base {
public:
    void fun() {
        cout << "FUN-A: DERIVED\n";
    }
    void fun2() {
        cout << "FUN2-A: DERIVED\n";
    }
};
int main() {
    A a;
    Base b;
    Base* q = &b;
    Base* p = &a;  // without virtual it will call parent;
    a.fun();
    p->fun(); // calling child due to virtual function i.e late binding;
    p->fun2(); // calling base or parent without virtual i.e early binging.

    q->fun();
    q->fun2();
    A* r = &a;
    r->fun();
    r->fun2();
    return 0;
}
// FUN-A: DERIVED
// FUN-A: DERIVED
// FUN2-BASE: EARLY BINDING
// FUN-BASE: LATE BINDING
// FUN2-BASE: EARLY BINDING
// FUN-A: DERIVED
// FUN2-A: DERIVED

// in early binding compiler decide type based on pointer type.
// in late binding it check vtable; kisko point kr rha hai;
