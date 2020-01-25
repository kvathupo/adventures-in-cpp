#include "basket.h"
#include <vector>

// defining the methods of my parameterized concrete class

namespace tst {

template<typename T>
MyBasket<T>::MyBasket() {
    sz = 0;
}

template<typename T>
void MyBasket<T>::add(T ele) {
    contents.push_back(ele);
    sz++;
}

template<typename T>
int MyBasket<T>::size() {
    return sz;
}

}
