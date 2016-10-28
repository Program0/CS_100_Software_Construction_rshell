#include "connector_b.h"
#include "and_connector.h"

And_Connector::And_Connector(Base* left, Base* right) : Connector_B(left, right) {
	
}
        
int And_Connector::execute() {
    int result = this->leftChild->execute();
    if (result == -1) //if error
        return -1;
    else{
        this->rightChild->execute();
        return 0;
    }
}
