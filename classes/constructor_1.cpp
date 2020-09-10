// NOT DONE
/*
 * TODO: 
 *  - Try deleting addresses in Basket destructor
 */
#define WILL_COMPILE 1
#include <iostream>

public class Basket {
private: 
    char** basket;
    int size;
public:
    Basket(int size)                            // constructor
        :this->size{size},
         basket{new char*[size]}
    {}
    ~Basket() {                                 // destructor
        for (char* ele : basket)    
            delete ele;
        delete[] basket;
    }

    Basket(const Basket& b);                    // copy constructor
    Basket& operator=(const Basket& b);         // copy assignment 

    Basket(Basket&& b);                         // move constructor
    Basket& operator=(Basket&& b);              // move assignment
}

#if !WILL_COMPILE
Basket::Basket(const Basket& b)
    :basket{new char*[b.size]},
    size{b.size}
{
    for 
}


#endif
