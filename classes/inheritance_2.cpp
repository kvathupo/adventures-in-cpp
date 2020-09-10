#include <iostream>

/*
 *  A follow-up to inheritance_1.cpp showing the dangers of a non-virtal 
 *  destructor. Thread sanitizers reveal that `my_precious` is never deleted!
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
    char* my_precious;
public:
    B() {
        std::cout << "B()\n";
        my_precious = new char('B');
    }
    ~B() {
        std::cout << "~B()\n";
        delete my_precious;
    }
};

int main() {
    A* a = new B;
    delete a;

    return 0;
}
