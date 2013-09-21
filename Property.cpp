#include "Property.hpp"

// ----------------------------------------------------------------------------
BaseProperty::BaseProperty( const std::string& a_identifier ) :
    m_identifier( a_identifier ),
    m_next( nullptr )
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
