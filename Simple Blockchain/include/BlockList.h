
/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 27/07/2021 */

#pragma once
#include "BlockNode.h"
#include "Node.h"

using namespace std;

class BlockList{
    BlockNode* head;
    BlockNode* tail; 
public:
    BlockList();
    BlockNode* getHead() const{return head;};
    BlockNode* getTail() const{return tail;};
    void addBlockNode(BlockNode* toAdd);
    bool isEmpty(){return head==NULL;};
    int getBalanceOf(string name, int initial_balance);
    string getTailHash();
    void clear();
};