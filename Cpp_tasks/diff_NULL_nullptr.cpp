// The difference between NULL and nullptr in C++ is as follows:

// NULL:

// NULL is a preprocessor macro that is typically defined as 0 or (void*)0.
// It is used to represent a null pointer value.
// The use of NULL is a legacy from C, where there was no dedicated keyword for the null pointer value.
// In C++, the use of NULL is still allowed for backward compatibility, but it is generally recommended to use nullptr instead.
// nullptr:

// nullptr is a keyword introduced in C++11 that represents the null pointer value.
// It is a dedicated null pointer literal, designed to be a more explicit and type-safe alternative to NULL.
// When using nullptr, the compiler can perform type checking and catch potential errors more effectively.
// nullptr is a literal that has the type std::nullptr_t, which is implicitly convertible to any pointer type.


#include <iostream>

int main() {
    int* p1 = NULL;   // Using NULL
    int* p2 = nullptr; // Using nullptr

    std::cout << "p1 is a null pointer: " << (p1 == NULL) << std::endl;
    std::cout << "p2 is a null pointer: " << (p2 == nullptr) << std::endl;

    // Pointer arithmetic with NULL
    int* p3 = p1 + 1; // This is allowed, but the behavior is undefined
    
    // Pointer arithmetic with nullptr
    int* p4 = p2 + 1; // This will not compile, as nullptr cannot be used in pointer arithmetic
    std::cout << p4 <<" .... "<< p3 <<std::endl;
    return 0;
}