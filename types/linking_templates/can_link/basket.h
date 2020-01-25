#pragma once
#include <vector>

namespace tst {

template<typename T>
class Basket {                                  // declaring abstract class
private:
    std::vector<T> contents;
    int sz;
public:
    virtual int size() = 0;
    virtual void add(T ele) = 0;
};

template<typename T>
class MyBasket : public Basket<T> {             // declaring concrete class
                                                // extending abstract one
private:
    std::vector<T> contents;
    int sz;
public:
    MyBasket();
    int size();
    void add(T ele);
};

// defining methods of concrete class

template<typename T>
MyBasket<T>::MyBasket() : contents{}, sz{0} {}

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

