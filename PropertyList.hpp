#ifndef PROPERTYLIST_HPP
#define PROPERTYLIST_HPP

#include <functional>
#include <string>
#include <map>

// ----------------------------------------------------------------------------
class PropertyList {
    struct PropertyBase {
                            PropertyBase( const type_info* a_type ) :
                                m_type( a_type ) {};
        virtual             ~PropertyBase() {};

        const type_info*    m_type;
    };

    template< class T >
    struct Property : public PropertyBase {
                            Property( const T& a_data ) :
                                PropertyBase( &typeid( T ) ),
                                m_data( a_data ) {};
                            ~Property() {};

        T                   m_data;
    };

public:
    template< class T >
    T*                  Set( const std::string&, const T& );

    template< class T >
    T*                  Get( const std::string& );

private:
    std::map< std::size_t, std::shared_ptr< PropertyBase > > m_properties;

};

// ----------------------------------------------------------------------------
template< class T >
T* PropertyList::Set( const std::string& a_key, const T& a_data ) {
    std::size_t hash = std::hash< std::string >()( a_key );
    m_properties[ hash ] = std::shared_ptr< PropertyBase >( new Property< T >( a_data ) );

    return &static_cast< Property< T >* >( m_properties[ hash ].get() )->m_data;
};

// ----------------------------------------------------------------------------
template < class T >
T* PropertyList::Get( const std::string& a_key ) {
    std::size_t hash = std::hash< std::string >()( a_key );
    auto result = m_properties.find( hash );

    if ( &typeid( T ) == result->second.get()->m_type ) {
        if ( result == m_properties.end() ) {
            return nullptr;
        } else {
            return &static_cast< Property< T >* >( result->second.get() )->m_data;
        };
    };
    
    return nullptr;
};

#endif
