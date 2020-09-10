// NOT DONE
#define WILL_COMPILE 1
#include <iostream>
// Q: Do I need to include string?
// #include <string>

//
//  Demonstration:
//      * explicit constructors
//      * Implicit casting with constructors
//

#if WILL_COMPILE
namespace kvathupo 
{

class MyString {
public:
    MyString() :contents{""}                                  // default constructor
    {}
    ~MyString() {}                                            // destructor

    MyString(std::string str) :contents{str}                  // constructor (str)
    {}
    MyString(int size) {                                      // constructor (int)
        contents.resize(size);
    }
    

    // Q: Do I call the copy constructor of str?
    MyString(const MyString& str) :contents{str}                // copy constructor
    {}
    MyString& operator=(const MyString& str) :contents{str} {   // copy assignment
        return *this;
    }
    
    // Note: There is no need to check against `this` since, by definition of
    // memory addresses, they are always unique!
    //
    // Q: Do I call the move constructor of str? Or do I need a std::move?
    MyString(MyString&& str) :contents{str}                     // move constructor
    {}
    MyString& operator=(MyString&& str) :contents{str} 
    {
        return *this;
    }

private:
    std::string contents;
};

}

#elif !WILL_COMPILE
namespace kvathupo 
{

public class MyString {
public:
    MyString() :contents{""}                                  // default constructor
    {}
    ~MyString() {}                                            // destructor

    MyString(const MyString& str) :contents{str}                
    {}
    MyString& operator=(const MyString& str) :contents{str} {   // Only constructors can
                                                                // can invoke member initializers 
        return *this;
    }
private:
    std::string contents;
};

}

#endif

int main() {
    std::cout << "initial test" << std::endl;
    return 0;
}
