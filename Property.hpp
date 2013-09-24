#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <string>

// ----------------------------------------------------------------------------
class BaseProperty {
    friend class PropertyList;

public:
                        BaseProperty( const std::string& a_identifier, const type_info* a_type );
    virtual             ~BaseProperty();

    const std::string&  GetIdentifier() const;

protected:
    BaseProperty* const GetNext() const;
    void                SetNext( BaseProperty* a_next );
    const type_info*    GetType() const;

private:
    std::string         m_identifier;
    const type_info*    m_type;

    BaseProperty*       m_next;

};

// ----------------------------------------------------------------------------
template < class T >
class Property : public BaseProperty {
public:
                        Property( const std::string& a_identifier, const T& a_data ) :
                            BaseProperty( a_identifier, &typeid( T ) ),
                            m_data( a_data ) {};
                        
                        ~Property() {};

    const T&            Get() const { return m_data; };
    void                Set( const T& a_data ) { m_data = a_data; };

private:
    T                   m_data;

};

// ----------------------------------------------------------------------------
class PropertyList {
public:
                        PropertyList();
                        ~PropertyList();

    template < class T >
    const T*            Get( const std::string& a_identifier );
    template < class T >
    void                Set( const std::string& a_identifier, const T& a_data );

private:
    BaseProperty*       m_head;

    template < class T >
    Property< T >*      Search( const std::string& a_identifier );
};

// ----------------------------------------------------------------------------
template < class T >
const T* PropertyList::Get( const std::string& a_identifier ) {
    Property< T >* prop = Search< T >( a_identifier );
    if ( prop != nullptr ) {
        return &prop->Get();
    };

    return nullptr;
};

// ----------------------------------------------------------------------------
template < class T >
void PropertyList::Set( const std::string& a_identifier, const T& a_data ) {
    Property< T >* prop = Search< T >( a_identifier );
    if ( prop != nullptr ) {
        prop->Set( a_data );
    } else {
        Property< T >* node = new Property< T >( a_identifier, a_data );

        if ( m_head == nullptr ) {
            m_head = node;
        } else {
            node->SetNext( m_head );
            m_head = node;
        };
    };
};

// ----------------------------------------------------------------------------
template < class T >
Property< T >* PropertyList::Search( const std::string& a_identifier ) {
    BaseProperty* node = m_head;
    while ( node != nullptr ) {
        if ( node->GetIdentifier() == a_identifier && node->GetType() == &typeid( T ) ) {
            return static_cast< Property< T >* >( node );
        };

        node = node->GetNext();
    };

    return nullptr;
};

#endif
