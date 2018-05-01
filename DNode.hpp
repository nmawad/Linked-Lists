/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DNode.hpp
 * Author: NoahAwad
 *
 * Created on April 1, 2017, 9:16 AM
 */

#ifndef DNODE_HPP_
#define DNODE_HPP_
#include <string>

using namespace std;

class DNode {
    friend class DLL;
    int data;
    DNode *next;
    DNode *prev;

public:
    DNode(int x);
    ~DNode();
};

#endif /* DNODE_HPP_ */
