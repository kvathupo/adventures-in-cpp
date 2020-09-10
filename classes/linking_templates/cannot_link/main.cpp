#include "basket.h"
#include <iostream>
#include <vector>

int main() {
    tst::MyBasket<int> my_basket;
    std::cout << "Size of basket = " << my_basket.size() << std::endl;
    my_basket.add(1);
    my_basket.add(2);
    std::cout << "Size of basket = " << my_basket.size() << std::endl;

    return 0;
}
