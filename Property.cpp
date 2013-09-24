#include "Property.hpp"

// ----------------------------------------------------------------------------
BaseProperty::BaseProperty( const std::string& a_identifier, const type_info* a_type ) :
    m_identifier( a_identifier ),
    m_next( nullptr ),
    m_type( a_type )
{
    
};

BaseProperty::~BaseProperty() {

};

const std::string& BaseProperty::GetIdentifier() const {
    return m_identifier;
};

BaseProperty* const BaseProperty::GetNext() const {
    return m_next;
};

void BaseProperty::SetNext( BaseProperty* a_next ) {
    m_next = a_next;
};

const type_info* BaseProperty::GetType() const {
    return m_type;
};

// ----------------------------------------------------------------------------
PropertyList::PropertyList() :
    m_head( nullptr )
{

};

PropertyList::~PropertyList() {
    while ( m_head != nullptr ) {
        BaseProperty* temp = m_head;
        m_head = m_head->GetNext();

        delete temp;
    };
};
