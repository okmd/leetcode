// When a variable in a class is declared static, space for it is allocated for the lifetime of the program. No matter how many objects of that class have been created, there is only one copy of the static member. So same static member can be accessed by all the objects of that class.

// A static member function can be called even if no objects of the class exist and the static function are accessed using only the class name and the scope resolution operator ::
#include<iostream>
using namespace std;
class A {
public:
    static int a; // throught the program; till termination; global, init=0
    A() {
        a = 0; // initialize when object is created or overwrite;
    }
    void show() {
        cout << "SHOW\n";
    }
    static void print() {
        cout << "a = " << a << endl;
    }
    static void change(int b) {
        a = b;
    }

};
int A::a = 3; // initialize; when object is not created;
int main() {
    A::print();
    A::change(40);
    A::print();
    // A::show();// non static
    A a;
    a.show();
    A::print();
    A::change(20);
    A::print();
    return 0;
}
// a = 3
// a = 40
// SHOW
// a = 0
// a = 20