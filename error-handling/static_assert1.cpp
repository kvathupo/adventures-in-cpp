#define WILL_COMPILE 1
#include <iostream>
#include <stdexcept>

/*
  Demonstration:
    - static_assert, exception handling, this pointer, class structure
  TODO:
    - Use boost for contract programming
*/

class Basket {
public:
#if WILL_COMPILE
    Basket(int apples, int oranges) {
        if (apples >= 0 && oranges >= 0) {
            this->apples = apples;
            this->oranges = oranges;
        } else {
            throw std::invalid_argument("Can't have negative fruits!");
        }
    }
#elif !WILL_COMPILE
    Basket(int apples, int oranges) {
        static_assert(apples >= 0);     // How can we check at compile-time?
                                        // apples >= 0 not constexpr
                                        // Require C++17
        static_assert(oranges >= 0);    // How can we check at compile-time?
                                        // oranges >= 0 not constexpr
                                        // Require C++17
        this->apples = apples;
        this->oranges = oranges;
    }
#endif
private:
    int apples;
    int oranges;
};

int main() {
#if WILL_COMPILE
    try {
        Basket my_basket(3, -10);
    } catch (const std::invalid_argument& e) {  // Require C++17, recommended
                                                // that const addr be passed.
        std::cout << e.what() << std::endl;
        return 0;
    }
#elif !WILL_COMPILE
#endif
    std::cout << "Do I reach here when I have an exception?\n";
    return 0;
}
