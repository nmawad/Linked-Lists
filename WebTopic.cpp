/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>
using namespace std;

WebTopic::WebTopic(string filename) {
    file = filename;
    wordlist = new SLL();
    currpriority = 3;
}

void WebTopic::getPriority(string line) {
    
    // determine the current priority, based on the tag that starts the line
    //See the header file for more details
    
    //The line is the tag, without the first <. This method uses the line to
    //determine the current priority as follows:
    //If the first 5 characters in the line match the word “title” (I used
    //line.compare for this), or the first 2 characters match either h1 or h2,
    //then the current priority is set to 1. If the first 2 characters are
    //anything between h3 and h6, then the priority is set to 2, and if it’s
    //anything else, it’s set to 3.
    if (line.compare(0, string::npos, "title") == 0 || line.compare(0, string::npos, "h1") == 0 || line.compare(0, string::npos, "h2") == 0)  
    {
        currpriority = 1;   
    }
    else if (line.compare(0, string::npos, "h3") == 0 || line.compare(0, string::npos, "h4") == 0 || line.compare(0, string::npos, "h5") == 0 || line.compare(0, string::npos, "h6") == 0)
    {
        currpriority = 2;
    }
    else
    {
        currpriority = 3;
    }
}

void WebTopic::printPage() {

    int prevPriority = 0;
    for (SNode *node = wordlist->first; node != nullptr; node = node->next) 
    {
        if (node->priority != prevPriority)
        {
            if (prevPriority > 0)
            {
                cout << endl << endl;
            }
 
            cout << "Priority " << node->priority << ":" << endl;
        }
        cout << node->word << ": " << node->priority << ", ";
        prevPriority = node->priority;
    }
        //Prints out the list of web page words and their priority. You can
        //look at my output below to see what mine looks like
}

void WebTopic::ReadFile() {
    ifstream infile(file.c_str(), ios::in); // open file
    string line = "";
    char c;
    while (infile.get(c)) {
        if (c == '<') {
            if (!line.empty()) {
                parseString(line);
                line = "";
            }
        } else if (c == '>') {
            getPriority(line);
            line = "";
        } else {
            line += c;
        }
    }
    cout << endl;
    infile.close();
}

string WebTopic::stripSpace(string s) {
    unsigned int i = 0;
    while (i < s.length()) {
        if (!isalpha(s[i])) {
            s.erase(i);
        }
        i++;
    }
    return s;
}

void WebTopic::parseString(string line) 
{
    unsigned int start = 0;
    line += ' ';
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        { 
            string word = line.substr(start, i - start);
            word = stripSpace(word);
            if (word != "")
            {
                wordlist->priorityInsert(word, currpriority);
            }
            start = i + 1;
        }
    }
    //takes the line and breaks it down into words (separated by space), calls
    //stripSpace to get rid of anything not alphanumeric, and then inserts each
    //word into the list along with its priority
}