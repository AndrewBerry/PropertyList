#include <iostream>
#include "Property.hpp"

int main() {
    PropertyList properties;

    properties.Set< std::string >( "name", "Jane" );
    properties.Set< int >( "age", 20 );
    properties.Set< float >( "height", 170.45f );

    auto name = properties.Get< std::string >( "name" );
    auto age = properties.Get< int >( "age" );
    auto height = properties.Get< float >( "height" );

    if ( name != nullptr ) {
        std::cout << *name << '\n';
    };
    if ( age != nullptr ) {
        std::cout << *age << '\n';
    };
    if ( height != nullptr ) {
        std::cout << *height << '\n';
    };
    
    std::cout << "\n\n";
    properties.Set< std::string >( "name", "John" );
    name = properties.Get< std::string >( "name" );
    if ( name != nullptr ) {
        std::cout << *name << '\n';
    };

    std::cin.get();
    return 0;
};
