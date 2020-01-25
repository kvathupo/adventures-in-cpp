## Lesson: Linker troubleshooting
First, attempt to compile the files in `./cannot_link/` as "usual" for a project that puts
declarations in header files, definitions in separate source files, and
`main()` in a single source file:
```
g++ basket.cpp main.cpp
```
It compiles, but the linker failed! This is since you [cannot separate](https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl)
the declaration of a template class from its definition.

With this in mind, let's compile the files in `./can_link/` with the parameterized 
`Basket` type defined and declared in our header file:
```
g++ main.cpp
```
