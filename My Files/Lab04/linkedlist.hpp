//
//  linkedlist.hpp
//  lab04
//
//  Created by Michael Kristy on 9/21/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class linkNode{
    
public:
    std::string data_;
    linkNode* nextNode_;
    
public:
    linkNode(std::string data);
};

class LinkedList {
    linkNode* root_;
    linkNode* tail_;
    linkNode* head_;
    
public:
    LinkedList();
    bool Insert(std::string);
    bool Search(std::string);
    bool Delete(std::string);
    void InOrder();
    void InOrder(linkNode*);
};


#endif /* linkedlist_hpp */
