/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: NoahAwad
 *
 * Created on April 1, 2017, 9:10 AM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main() {
    WebTopic *x = new WebTopic("Dogs and Puppies.htm");
    //or another web page – I haven’t
    //tested it extensively, but it should work for any basic html page
    x->ReadFile();
    x->printPage();
    return 0;
}