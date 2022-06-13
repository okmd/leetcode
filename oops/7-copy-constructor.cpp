// A copy constructor is a member function that initializes an object using another object of the same class.
#include<iostream>
using namespace std;
class A {
public:
    int x, y, * ptr;
    A(int a, int b, int c) {
        cout << "Deep copy: Custom CC.\n";
        x = a;
        y = b;
        ptr = new int;
        *ptr = c;
    }
    void show() {
        cout << "x=" << x << ", y=" << y << ", ptr=" << *ptr << endl;
    }
    // copy constructor
    // pass by ref: copy the content;
    A(const A& a) { // const is used to denote not changing the orignal value; cab be removed;
        x = a.x;
        y = a.y;
        ptr = new int;
        *ptr = *(a.ptr);
    }
    ~A() {
        delete ptr;
    }
};
class B {
public:
    int x, y, * ptr;
    B(int a, int b, int c) {
        cout << "Shallow copy: Default CC.\n";
        x = a;
        y = b;
        ptr = new int;
        *ptr = c;
    }
    void show() {

        cout << "x=" << x << ", y=" << y << ", ptr=" << *ptr << endl;
    }
    // default copy constructor
    // both object point to same location.
    ~B() {
        delete ptr;
    }
};

int main() {
    A a1(2, 3, 4);
    A a2 = a1; // deep copy as user-defined CC
    a1.show();
    a2.show();
    (*a2.ptr)++;
    a1.show();
    a2.show();
    cout << "-------------------\n";
    // B
    B b1(5, 6, 7);
    B b2 = b1;  // default copy constructor if not defined in class; shallow copy;
    b1.show();
    b2.show();
    (*b2.ptr)++; // both b1 and b2 pointer value got increamented; as default copy just copeied the same address instead of content;
    b1.show();
    b2.show();
    return 0;
}

// NOTE: default constructor create a shallow copy;
// user-defined CC create a deep copy
// The main difference between Copy Constructor and Assignment Operator is that the Copy constructor makes a new memory storage every time
//  it is called while the assignment operator does not make new memory storage.