#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <type_traits>

/*
 *  Demonstration:
 *      - Placement of const for pointers
 *      - Smart pointers not needing deletion (RAII)
 *      - Pass by value for pointers
*/

// Modifiable pointer to read-only data
template<typename T>
void print_vect(const std::vector<T>* v, std::string v_name) {
    if (v == nullptr) {
        std::cout << "Can't print nullptr!\n";
        return;
    }

    std::cout << v_name << " = {";
    for (auto i = 0; i < v->size(); i++) {
        if (i + 1 == v->size())
            std::cout << (*v)[i] << "}\n";
        else 
            std::cout << (*v)[i] << ", ";
    }
}

// Modifiable pointer to read-only data
template<typename T>
void nullify_vect(const std::vector<T>* v, std::string v_name) {
    v = nullptr;
    std::cout << "Just set " << v_name << " to nullptr!\n";
}

// Read-only pointer to modifiable data
// Run-time error if used
template<typename T,
    typename = std::enable_if<std::is_constructible<T>::value>>
void nullify_vect_again(std::vector<T>* const v, std::string v_name) {
    T t{};
    std::fill(v->begin(), v->end(), t);
    std::cout << "Just filled " << v_name << " with default values!\n";
}

int main() {
    std::vector<int>* dumb_v = new std::vector<int>(5);
    std::unique_ptr<std::vector<int>> smart_v(new std::vector<int>(5));
    
    std::generate(dumb_v->begin(), dumb_v->end(), 
        []() {
            static int i = 0;
            return i++;
        });
    std::generate(smart_v->begin(), smart_v->end(), 
        []() {
            static int i = 0;
            return i--;
        });


    print_vect(dumb_v, "dumb_v");
//  Can't pass smart pointer where raw pointer is expected!
//    print_vect(smart_v, "smart_v");   
    print_vect(smart_v.get(), "smart_v");

    std::cout << "\n";
    nullify_vect(dumb_v, "dumb_v");
    print_vect(dumb_v, "dumb_v");
    
    std::cout << "\n";
    std::cout << "We were able to print \"dumb_v\" since we passed by value :^)\n";

    std::cout << "\n";
    nullify_vect_again(dumb_v, "dumb_v");
    print_vect(dumb_v, "dumb_v");

    delete dumb_v;
    return 0;
}
