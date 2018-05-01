/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//
#include <string>
#include <iostream>
#include "DLL.hpp"
#include "DNode.hpp"

using namespace std;

DLL::DLL() : first(nullptr), last(nullptr), size(0)
{ 
}

DLL::DLL(int size) {
    this->size = size;
    DNode *prevNode = nullptr;
    
    for (int i = 0; i < size; i++) {
        int data = rand() % 101;
        DNode *newNode = new DNode(data);
        newNode->prev = prevNode;
        
        if (prevNode != nullptr)
        {
            prevNode->next = newNode;
        }
        
        if (i == 0)
        {
            first = newNode;
        }
        else if (i == size - 1)
        {
            last = newNode;
        }
        
        prevNode = newNode;
        
    }
}

DLL::~DLL()
{
    DNode *next;
    for (DNode *node = first; node != nullptr; node = next)
    {
        next = node->next;
        delete node;  
    }
}   

void DLL::printDLL(){
    for (DNode *currentNode = first; currentNode != nullptr; currentNode = currentNode->next) 
    {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

void DLL::printReverse()
{
    for (DNode *currentNode = last; currentNode != nullptr; currentNode = currentNode->prev)
    {
        cout << currentNode->data << " ";
    }
    cout << endl;
}

void DLL::addFirst(int data)
{
    DNode *newNode = new DNode(data);
    first = newNode;
    last = newNode;
    size++;  
}

void DLL::addAtFront(int data)
{
    DNode *newNode = new DNode(data);
    newNode->next = first;
    first = newNode;
    size++;  
}

void DLL::push(int data)
{
    DNode *newNode = new DNode(data);
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
    
    if (size == 0)
    {
        first = newNode;
    }
    size++;
}

void DLL::insertInOrder(int data)
{
    DNode *newNode = new DNode(data); 
    for (DNode *node = first; node != nullptr; node = node->next)
    {
        if (node->data > data)
        {
            newNode->next = node;
            newNode->prev = node->prev; 
            if (node->prev != nullptr)
            {
                node->prev->next = newNode;
            }
            node->prev = newNode;
        }
    }
}