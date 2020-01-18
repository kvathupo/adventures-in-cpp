## (Mis)Adventures in C++
This repo serves to demonstrate various features of modern C++, primarily for
my own education. If, however, you find it useful, feel free to fork for your
own learning!

__Currently working in:__ C++17

__Platform:__ Latest stable release of GCC
## TODO:
* Add CMake

## Internal Dev Tips
Compile with `g++ -std=c++2a -L-fsanitize=address -L-fsanitize=thread blahblah.cpp`.
* Get to this dir with path %CPP%
* To use gcc [instrumentation](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)
(sanitizers), prepend -L to the flag
    * `-L-fsanitize=address`
        * Detect out-of-bounds and use-after-free bugs
    * `-L-fsanitize=thread`
        * Detect data race bugs
    * `-L-fsanitize=leak`
        * Detect memory leaks
    * `-L-fsanitize=undefined`
        * Detect runtime UB
