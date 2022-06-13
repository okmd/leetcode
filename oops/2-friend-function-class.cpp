// it is not class member function but a freind
// declared inside the class but defined outside class;
// it can access any member including private but can acess direclty;
// it has no caller object and membersihp label;
// friend function can be declared anywhere in private or public as they are not mem function;
// so membership does not matter;
#include<iostream>
using namespace std;
// forward declaration to tell compiler that calss extist;
class B;
class C;

class A {
    int a;
public:
    A() :a(10) {}
    friend void fun(A, B, C);
    friend int operator+(A, B);
};


class B {
    int b;
public:
    B() :b(15) {}
    friend void fun(A, B, C);
    friend int operator+(A, B);
};


class C {
    int c;
public:
    C() :c(20) {}
    friend void fun(A, B, C);
    friend int operator+(A, B);
};


// define with no keyword friend and membership label;
void fun(A o1, B o2, C o3) {
    cout << "I am friend\nsum=";
    // can;t access members direclty as cout<<a;
    cout << o1.a + o2.b + o3.c << endl;
}
int operator+(A a, B b) {
    return a.a + b.b;
}
int main() {
    A a;
    B b;
    C c;
    fun(a, b, c);
    int sum = a + b; // int sm = a.operator+(b);
    cout << sum;
    return 0;
}
// application
// when some taskt is to be performed over object of mutiple class;
// friend of multiple class
// operator overloding using friend function;