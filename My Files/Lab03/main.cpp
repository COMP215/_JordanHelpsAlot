//
//  main.cpp
//  binaryTree
//
//  Created by Michael Kristy on 9/14/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include <iostream>

//
//  main.cpp
//  linkedList
//
//  Created by Michael Kristy on 9/12/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include <iostream>
#include <random>
#include <time.h>
using namespace std;


class node
{
public:
    node();
    double num_data_entry;
    node *pointer_to_greater;
    node *pointer_to_lesser;

};

node :: node (){
    num_data_entry = 0;
    pointer_to_greater = 0;
    pointer_to_lesser = 0;
}

class linkedList
{
public:
    linkedList();
    void addNode (int passed_var);
    void printList();
    node base_node;
    node *last_posistion;
    node *curr_posistion;
    bool path_finder(int passed_var, node *node_loc, node *new_node_loc);
    int counter = 0;
    void printRight(node *base);
};

linkedList :: linkedList (){
    node *head;
    head = &base_node;
    curr_posistion = &base_node;
    curr_posistion->num_data_entry = 0;

}

void linkedList :: addNode (int passed_var){
    node *new_node = new node;
    //new_node->num_data_entry = passed_var;
    if (curr_posistion->pointer_to_greater == 0 && curr_posistion->pointer_to_lesser == 0 && curr_posistion->num_data_entry == 0)
    {
        curr_posistion->num_data_entry = passed_var;
        cout << "base of " <<curr_posistion->num_data_entry;

    }
    else
    {
        path_finder(passed_var, curr_posistion, last_posistion);
    }
}

bool linkedList::path_finder(int passed_var, node *node_loc, node *new_node_loc)
{
    cout << "A";
    while (passed_var < node_loc->num_data_entry) //While left is the correct way to go
    {
        cout << "B";
        if (node_loc->pointer_to_lesser == 0)
        {
            cout << "C";
            node_loc->pointer_to_lesser = new_node_loc;
            new_node_loc->num_data_entry = passed_var;
            return true;
        }
        else
        {
            cout << "D";
            node_loc = node_loc->pointer_to_lesser;
            cout << node_loc->num_data_entry;
        }
    }
    while (passed_var > node_loc->num_data_entry)
    {
        cout << "Z";
        if (node_loc->pointer_to_greater == 0)
        {
            node_loc->pointer_to_greater = new_node_loc;
            new_node_loc->num_data_entry = passed_var;
            return true;
        }
        else
        {
            node_loc = node_loc->pointer_to_greater;
        }
    }

}

void linkedList :: printRight (node *base)
{
    while (base->pointer_to_greater != 0)
    {
        cout << "| Value = " << base->num_data_entry << " " << endl;
        base = base->pointer_to_greater;
    }

}

int main() {
    linkedList test;
    test.addNode(5);
    test.addNode(4);
    test.addNode(3);
    //test.addNode(2);
    //test.printRight(test.curr_posistion);



}

