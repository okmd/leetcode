// If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time. One of the important advantages of using an 
// inline function is that it eliminates the function calling overhead of a traditional function.
#include<iostream>

#define difference(a,b) (a-b);
using namespace std;

inline int sum(int a, int b) {
    return a + b;
}

int main() {
    cout << sum(4, 5) << endl;
    cout << difference(4, 5); // cant apply endl here
    return 0;
}

// NOTE: in class member functions are already inline by default;

// not perform inlining in such circumstances
// 1) If a function contains a loop. (for, while, do-while)
// 2) If a function contains static variables.
// 3) If a function is recursive.
// 4) If a function return type is other than void, and the return statement doesn’t exist in function body.
// 5) If a function contains switch or goto statement.

// Advantange
// 1) Function call overhead doesn’t occur.
// 2) It also saves the overhead of push/pop variables on the stack when function is called.
// 3) It also saves overhead of a return call from a function.
// 4) When you inline a function, you may enable compiler to perform context specific optimization on the body of function. Such optimizations are not possible for normal function calls. Other optimizations can be obtained by considering the flows of calling context and the called context.
// 5) Inline function may be useful (if it is small) for embedded systems because inline can yield less code than the function call preamble and return.

// Disadvantage
// 1) increase binary exe file size.
// 2) cause thrashing
// 3) more rgister req
// 4) compile time overhead.

// C-Macro vs inline fun
// According to Dr. Bjarne Stroustrup the creator of C++ that macros are almost never necessary in C++ and they are error prone. 
// There are some problems with the use of macros in C++. Macro cannot access private members of class. Macros looks like function call but they are actually not.