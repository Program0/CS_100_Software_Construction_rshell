#include "or_connector.h"

Or_Connector::Or_Connector(Base *left, Base *right):Connector_B(left, right){

}

Or_Connector::~Or_Connector(){
    if(this->leftChild !=NULL){
        delete this->leftChild;
    }
    if(this->rightChild!=NULL){
        delete this->rightChild;
    }
}

int Or_Connector::execute(){

}
