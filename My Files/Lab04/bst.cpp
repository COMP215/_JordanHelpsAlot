
//
//  binarysearchtree.cpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include "bst.h"
#include <string>
#include <iostream>
using namespace std;

Node::Node(string data) {
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
}

bool BinarySearchTree::Insert(string data) {
    if (root_ == NULL) {
        // Empty tree, make a root
        root_ = new Node(data);
        return true;
    } else {
        // Non-empty tree, find correct position for data
        Node* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, fail to insert
                return false;
            } else if (data < curr->data_) {
                // Lexicographically lesser, find location to the left
                if (curr->left_ == NULL) {
                    curr->left_ = new Node(data);
                    return true;
                } else {
                    curr = curr->left_;
                }
            } else {
                // Lexicographically greater, find location to the right
                if (curr->right_ == NULL) {
                    curr->right_ = new Node(data);
                    return true;
                } else {
                    curr = curr->right_;
                }
            }
        }
    }
    return false;

}

bool BinarySearchTree:: Search(string data){

    bool cutWhile = false;

    while(cutWhile != true){

        if(data == root_->data_){
            cout << "We found: " << root_->data_ << endl;
            cutWhile = true;
            return true;
        }

        else if(data > root_->data_ && root_->right_ != NULL){
            root_ = root_->right_;
            cutWhile = false;
        }

        else if(data < root_->data_ && root_->left_ != NULL){
            root_ = root_->left_;
            cutWhile = false;
        }
        else{
            cout << "Data Entry Not Found" << endl;
            cutWhile = true;
            return true;
        }

    }
    return false;
}

void BinarySearchTree::InOrder(){
    if(root_ != NULL){
        InOrder(root_);
    }
}

void BinarySearchTree::InOrder(Node* node) {
    if(node->left_ != NULL){
        InOrder(node->left_);
    }
    cout << node->data_ << endl;
    if(node->right_ != NULL){
        InOrder(node->right_);
    }
}
