#include "connector_b.h"

And_Connector::And_Connector(Base* left, Base* right) : Connector_B(left, right) {
	
}
        
And_Connector::execute() {
	int result = left->execute();
    if (result == -1) //if error
        return -1;
        right->execute();
        return 0;
}