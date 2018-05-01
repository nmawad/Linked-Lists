/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "SNode.hpp"

using namespace std;
        
SNode::SNode(string word, int p): word(word), priority(p), next(nullptr) {

}

SNode::~SNode() {
    
}

void SNode::printNode() {

    cout << word << ":" << priority;
}