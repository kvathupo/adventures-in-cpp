#define WILL_COMPILE 1
#include <iostream>

/*
  Demonstration:
    - Unlike plain enums that have the basic binary operators and 
equality, class enums have no such operators
    - To compensate, class enums allow the reuse of enum values. Generally
more type-safe.

*/
int main() {
    enum class Letter { a, b, c, d};
    enum class DifferentLetter { d, e, f, g};
    enum PlainLetter { a, b, c, d}; 

    Letter my_letter = Letter::d;   // No need to prepend `enum`, as in Java
    DifferentLetter my_letter_2 = DifferentLetter::d;
    PlainLetter old_letter = d;
#if WILL_COMPILE
    bool cond1 = 1 + old_letter; // Evaluates to 1
    std::cout << "old_letter = " << old_letter << std::endl;
#elif !WILL_COMPILE
    enum MyEnum { a, b, c, d}; 
    enum MyEnum_Copy { a, b, c, d, e}; // Conflicts with previous enum declaration
    bool condit = (my_letter == 0);  // No operator==
    bool condit = 1 + my_letter; // No operator+
    std::cout << "my_letter_2 = " << my_letter_2 << std::endl; // No operator<<
    bool condit = (old_letter == 0);  // OK, plain old enum
    bool condit = 1 + old_letter; // OK, plain old enum
#endif
    return 0;
}
