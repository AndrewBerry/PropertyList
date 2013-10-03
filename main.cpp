#include <iostream>
#include "PropertyList.hpp"

int main() {
    PropertyList properties;

    properties.Set< int >( "test_int1", 137 );
    properties.Set< float >( "test_float1", 13.03f );

    int* test_int1 = properties.Get< int >( "test_int1" );
    float* test_float1 = properties.Get< float >( "test_float1" );
    int* test_float2 = properties.Get< int >( "test_float1" );

    if ( test_int1 != nullptr ) {
        std::cout << *test_int1 << '\n';
    };
    if ( test_float1 != nullptr ) {
        std::cout << *test_float1 << '\n';
    };
    if ( test_float2 != nullptr ) {
        std::cout << *test_float2 << '\n';
    };

    std::cin.get();
    return 0;
};

/*
OUTPUT:
===========
137
13.03
===========
*/
