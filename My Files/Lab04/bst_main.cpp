//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "bst.h"


using namespace std;

int main(int argc, const char * argv[]) {

    BinarySearchTree* words_tree = new BinarySearchTree();

    ifstream readFile;
    string line;
    double counter=0;

    readFile.open("words.txt");
    if (readFile.is_open())
    {
        while (getline(readFile,line))
        {
            words_tree->Insert(line);
        }
    }

    std::cout << "Hello, World!\n";
    words_tree->InOrder();
    words_tree->Search("hello");
    return 0;
}
