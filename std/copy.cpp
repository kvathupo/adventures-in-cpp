// NOT DONE
#define WILL_COMPILE 1
#define WILL_RUN 0 
#include <iostream>
#include <vector>

/*
  Version: C++20
  Demonstration:
    - std::copy changes in c++20 with constexpr and execution policies
*/

int main() {
    std::vector<int> a{1, 2, 3, 4, 5};
    std::vector<int> b;

    std::cout << "Prior to invoking std::copy()" << std::endl;
    std::cout << "Size of a = " << a.size() << std::endl;
    std::cout << "Size of b = " << b.size() << std::endl;

#if WILL_RUN
    b.reserve(a.size());
    std::cout << "After reserving" << std::endl;
    std::cout << "Size of a = " << a.size() << std::endl;
    std::cout << "Size of b = " << b.size() << std::endl;

    std::copy(a.begin(), a.end(), b.begin());

    std::cout << "After invoking std::copy()" << std::endl;
    std::cout << "Size of a = " << a.size() << std::endl;
    std::cout << "Size of b = " << b.size() << std::endl;
    return 0;
}
// Will run, but not as intended (won't copy elements)
#elif !WILL_RUN
    std::copy(a.begin(), a.end(), std::back_inserter(b));                       // Do I need to reserve?
                                                                                // Yes.
    std::cout << "After invoking std::copy()" << std::endl;
    std::cout << "Size of a = " << a.size() << std::endl;
    std::cout << "Size of b = " << b.size() << std::endl;

    return 0;
}
#endif
