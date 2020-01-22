#include <iostream>
#include <cstddef>
#define WILL_COMPILE 1

//
//  Demonstration:
//      * When an overloaded function intakes more than one type of pointer,
//  it is UB to pass a null pointer, without overloading for the null pointer
//  types. Will not compile otherwise.
//      * Can't convert between pointer types that have no inheritance
//  relationship.
//      * All memory allocated by new must be free'd with delete or delete[].
//  Does not abide by RAII.
//

void foo(int* val) {
    std::cout << "foo: obtained " << *val << std::endl;
}
void foo(float* val) {
    std::cout << "foo: obtained " << *val << std::endl;
}

int main() {
    float *pi = new float;
    *pi = 3.14;
    
#if WILL_COMPILE
    int *int_pi = new int;
    *int_pi = static_cast<int>(*pi);

    foo(pi);
    foo(int_pi);
#elif !WILL_COMPILE
    foo(static_cast<int*>(pi));         // No inheritance relationship betwen these pointers
    foo(nullptr);                       // call of overloaded ‘foo(std::nullptr_t)’ is ambiguous
#endif
    delete pi;
    delete int_pi;

    return 0;
}
