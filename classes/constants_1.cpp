#include <iostream>
#include <vector>
#include <memory>

/*
  Demonstration:
    - Placement of const for pointers
    - Smart pointers not needing deletion (RAII)
    - Pass by value for pointers
*/

/* 
    Pointer data read-only. Pointer is modifiable.
*/
template<typename T>
void printVect(const std::vector<T>* vct) {
    std::cout << "Now printing out vector" << std::endl;
    for (T ele : *vct) {
        std::cout << ele << std::endl;
    }
    std::cout << "Done printing out vector" << std::endl;
}

/*
    Pointer data read-only. Pointer is modifiable.
*/
template<typename T>
void makeVectNull(const std::vector<T>* vct) {
    std::cout << "Now setting to nullptr" << std::endl;
    vct = nullptr;
}

/* 
    Pointer data modifiable. Pointer is read-only.

    Will compile, but fail at run time (modifying pointer we promised to keep
    constant).
*/
template<typename T>
void makeVectNull2(std::vector<T>* const vct) {
    std::cout << "Now setting to nullptr" << std::endl;
    vct = nullptr;
    std::cout << "Done setting to nullptr" << std::endl;
}

int main() {
    std::vector<int>* v_1 = new std::vector<int>;        // Raw pointers strongly discouraged
                                                         // Correct initialization
    std::vector<int>* v_2 = new std::vector<int>(2);        // Raw pointers strongly discouraged
                                                         // Incorrect initialization
                                                         // push_back allocates memory for us!
                                                         // (see what happens with printVect)
    std::unique_ptr<std::vector<int>> v_3(new std::vector<int>(2));     // recommended

    for (auto i = 1; i <= 2; i++) {
        (*v_1).push_back(i);
        (*v_2).push_back(i);
        (*v_3).push_back(i);
    }

    std::cout << "Printing Vector 1 correctly:" << std::endl;
    printVect(v_1);
    std::cout << "Printing Vector 2 incorrectly (allocated 2 extra spaces!):" << std::endl;
    printVect(v_2);
//    printVect(v_3);                   // Will not compile (type mismatch)
    makeVectNull(v_1);                  // Will compile without memory leak 
                                        // (We pass the pointer by VALUE!)

    delete v_1;
    delete v_2;                         // Need to delete to prevent memory leak
                                        // Observe no such need to delete unique_ptr
                                        // (RAII)
    return 0;
}
