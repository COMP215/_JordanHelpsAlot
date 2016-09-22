

#include "linkedlist.hpp"
using namespace std;

linkNode::linkNode(string data){
    data_ = data;
    nextNode_ = NULL;
}

LinkedList:: LinkedList(){
    root_ = NULL;
    tail_ = NULL;
}

bool LinkedList:: Insert(string data){
    //cout << data << endl;
    if(root_ == NULL){
        root_ = new linkNode(data);
        tail_ = root_;
        return true;
    }
    else{
        tail_->nextNode_ = new linkNode(data);
        tail_ = tail_->nextNode_;
        return true;
    }
    return false;
}

bool LinkedList::Search(string data){
    
    bool checkTF = false;
    
    while(checkTF != true){
        if(data == root_->data_){
            cout << "Located: " << data << endl;
            checkTF = true;
            return true;
        }
        else if(root_->data_ != data && root_->nextNode_ != NULL){
            
            root_ = root_->nextNode_;
            checkTF = false;
        }
    }
    
    cout << "There is no data entry matching: " << data << endl;
    
    return false;
}

//void LinkedList::InOrder(){
//    if(root_ != NULL){
//        InOrder(head_);
//    }
//}
//
//void LinkedList::InOrder(linkNode* head_){
//    cout << head_->data_ << endl;
//    if(head_->nextNode_ != NULL){
//        head_ = head_->nextNode_;
//        InOrder(head_);
//    }
//}













