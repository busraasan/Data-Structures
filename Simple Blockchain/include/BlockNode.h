/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 27/07/2021 */

#pragma once
#include "Node.h"

using namespace std;

class BlockNode{
    Node* head = NULL;
    BlockNode *next = NULL;
    string hash = "0";
public:
    BlockNode();
    void addTransaction(Node* toAdd);
    string getHash() const{return hash;};
    BlockNode* getNext() const{return next;};
    Node* getHead() const{return head;};
    void setNext(BlockNode* next){this->next = next;};
    void setHash(string hash);
    string transactionString();
    void clear();
};