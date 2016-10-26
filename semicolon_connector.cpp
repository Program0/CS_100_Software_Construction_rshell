#include "connector_u.h"

Semicolon_Connector::Semicolon_Connector(Base* child) : Connector_U(child) {
	
}
        
Semicolon_Connector::execute() {
	int result = child->execute();
    return result;
}