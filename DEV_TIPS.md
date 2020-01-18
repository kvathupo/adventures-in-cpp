#### Internal Dev Tips
Compile with `g++ -std=c++2a blahblah.cpp`.
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
