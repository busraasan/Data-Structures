/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 27/07/2021 */

#include "md5.h"
#include "BlockNode.h"
#include "Node.h"
#include <iostream>

using namespace std;

BlockNode::BlockNode(){
    this->next = NULL;
    this->head = NULL;
}

void BlockNode::addTransaction(Node* toAdd){
    //if empty
    if(head==NULL){
        head = toAdd;
        return;
    } else { //add to the end
        Node* current = head;
        while(current->getNext()){
            current = current->getNext();
        }
        current->setNext(toAdd);
    }
}

void BlockNode::setHash(string hash){
    MD5 md5;
    this->hash = md5(hash);
}

string BlockNode::transactionString(){
    Node* current = head;
    string str="";
    while(current){
        str += current->getFrom() + current->getTo() + to_string(current->getAmount());
        current = current->getNext();
    }
    return str;
}

void BlockNode::clear(){
    Node* temp = head;
    Node* clr;
    while(temp){
        clr = temp->getNext();
        delete temp;
        temp = clr;
    }
}