/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <stdlib.h>
#include "DNode.hpp"

using namespace std;

DNode::DNode(int k) {
    data = k;
    next = nullptr;
    prev = nullptr;
}

DNode::~DNode() {
    if (next != nullptr || prev != nullptr) {
        cout << "deleting this DNode may cause a memory leak" << endl;
    }
}