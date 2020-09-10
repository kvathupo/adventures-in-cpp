#include <iostream>

/*
 *  In overwhelmingly all cases, a destructor should be virtual to allow for 
 *  dynamic dispatch (deletion of the child class). This is important since
 *  due to __object slicing__, polymorphism is done in C++ with references
 *  or addresses.
 *
 *  Note:
 *      * Although this code compiles, it can lead to a memory leak if there
 *  is dynamically allocated member variables (see inheritance_2.cpp)
 */

class A {
public:
    A() {
        std::cout << "A()\n";
    }
    ~A() {
        std::cout << "~A()\n";
    }
};

class B : public A {
public:
    B() {
        std::cout << "B()\n";
    }
    ~B() {
        std::cout << "~B()\n";
    }
};

int main() {
    A* a = new B;
    delete a;

    return 0;
}
