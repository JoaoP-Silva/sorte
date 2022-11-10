#ifndef SSTACK_H
#define SSTACK_H


#include <iostream>


//Class node to represent a container in the stack.
class Node{
    private:
        int Val;
        Node* Next;
    
    public:
        //Default empty node constructor.
        Node();
        //Node constructor with value.
        Node(int val);
        //Node constuctor with value and next pointer.
        Node(int val, Node* next);

        //Access methods to Node
        int getVal();
        Node* getNext();
        void setVal(int val);
        void setNext(Node* next);
};


class Stack{
    private:
        Node* Top;
        int Size;

    public:
        //Empty stack constructor.
        Stack();

        //Method to access the top of stack.
        int front();

        //Method to add a Node to the top of the stack
        void push(int val);

        //Method to get the top of the stack. The item is removed from stack.
        int pop();

        //Method to test if the stack is empty. Returns 1 if size equals zero and 0 otherwise.
        int isEmpty();

        //Method to get the stack size.
        int getSize();

};






#endif