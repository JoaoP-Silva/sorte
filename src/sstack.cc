#include "sstack.h"

//Node constructors
Node::Node() : Val(NULL), Next(nullptr) {};
Node::Node(int val) : Val(val), Next(nullptr) {};
Node::Node(int val, Node* next) : Val(val), Next(next) {};

//Node access methods
Node* Node::getNext(){ return this->Next; }
int Node::getVal(){ return this->Val; }
void Node::setNext(Node* next){ this->Next = next; }
void Node::setVal(int val){ this->Val = val; }



//Stack constructors
Stack::Stack() : Top(nullptr), Size(0) {};

//Stack methods
int Stack::front(){
    return this->Top->getVal();
}

int Stack::getSize(){
    return this->Size;
}

int Stack::isEmpty(){
    if (this->Size == 0){
        return 1;
    }
    else return 0;
}

int Stack::pop(){
    if(this->isEmpty()){
        return NULL;
    }
    else{
        int f = this->front();
        Node* previousTop = this->Top;
        Top = previousTop->getNext();
        delete previousTop;
        this->Size--;
        return f;
    }
}

void Stack::push(int val){
    Node* newTop = new Node(val, this->Top);
    this->Top = newTop;
    this->Size++;
}


Stack::~Stack(){
    while(!this->isEmpty()){
        this->pop();
    }
}