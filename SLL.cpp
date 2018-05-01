/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SLL.hpp"

using namespace std;

SLL::SLL(): first(nullptr), last(nullptr), p2(nullptr), size(0) {

}

SLL::~SLL() {
    
    SNode *nextNode;
    for (SNode *currentNode = first; currentNode != nullptr; currentNode = nextNode)
    {
        nextNode = currentNode ->next;
        delete currentNode;
    }
            
}

void SLL::printSLL() {
    int prevPriority = 0;
    for (SNode *currentNode = first; currentNode != nullptr; currentNode = currentNode->next)
    {
        if (currentNode->priority != prevPriority)
        {
            if (prevPriority > 0)
            {
                cout << endl;
                cout << endl;
            }
            
            cout << "Priority " << currentNode->priority << ":" << endl; 
        }
        
        currentNode->printNode();
        cout << ", ";
        
        prevPriority = currentNode->priority;
    }
}
//used for testing purposes only, and you’ve already written this…

void SLL::priorityInsert(string s, int p) {
    SNode *newNode = new SNode(s, p);
    
    if (size == 0)
    {
        first = newNode;
        last = newNode;
        size++;
        return;
    }
    
    if (p == 1)
    {
        newNode->next = first;
        first = newNode;
    }
    else if (p == 3)
    {
        last->next = newNode;
        last = newNode;
    }
    else if (p == 2)
    {
        if (p2 == nullptr)
        {
            if (first->priority == 3)
            {
                newNode->next = first;
                first = newNode;
            }
            else
            {
                SNode *currentNode;
                SNode *prevNode = nullptr;
                
                for (currentNode = first; currentNode != nullptr && currentNode->priority == 1; currentNode = currentNode->next)
                {
                    prevNode = currentNode;  
                }
                
                newNode->next = prevNode->next;
                prevNode->next = newNode;
                p2 = newNode;
            }
        }
        else
        {
            newNode->next = p2->next;
            p2->next = newNode;
            p2 = newNode;  
        }
        
    }
    
    size++;
}

//(8 pts)
//This method creates a new node with s as the word and p as the priority and,
//if the priority is 1, adds the new node to the beginning of the list, if it
//is 3, adds the node to the end of the list, and if it’s 2, it will insert it
//into the list right after pointer p2 (which is the last node with a priority
//of 2. In essence, all the nodes with a priority of 1 are at the beginning
//of the list, all the nodes with a priority of 2 are in the middle of the
//list, and all the nodes with a priority of 3 are at the end of the list.

void SLL::push(SNode *n)
{
    n->next = nullptr;
    
    if (size == 0)
    {
        first = n;
        last = n;           
    }
    else
    {
        last->next = n;
        last = n;
    }
    
    size++;
}
//(4 pts)
// pushes n onto the end of the stack (remember to reset the last pointer)

void SLL::addAtFront(SNode *n)
{
    if (size == 0)
    {
        first = n;
        last = n;           
    }
    else
    {
        n->next = first;
        first = n;
    }
    
    size++;  
}
//(5 pts)
//adds n to the beginning of the list (remember to reset the first pointer)