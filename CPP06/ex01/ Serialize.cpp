#include "Serialize.hpp"

Serialize::Serialize() { }

Serialize::Serialize( const Serialize& src ) { (void)src; }

Serialize& Serialize::operator=(  const Serialize& src  ) { (void)src; return *this; }

Serialize::~Serialize() { }

uintptr_t Serialize::serialize( Data* ptr ) {

}

Serialize::Data* Serialize::deserialize( uintptr_t raw ) {

}
