/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 27/07/2021 */

#include "md5.h"
#include "BlockNode.h"
#include "BlockList.h"
#include "Node.h"
#include <iostream>

using namespace std;

BlockList::BlockList(){
    this->head = NULL;
    this->tail = NULL;
}

void BlockList::addBlockNode(BlockNode* toAdd){
    
    BlockNode* current;
    current = head;
    //if empty
    if(head==NULL){
        head = toAdd;
        tail = toAdd;
        return;
    } else { //add to the end
        tail->setNext(toAdd);
        Node* transaction;
        transaction = tail->getHead();
        toAdd->setHash(tail->getHash() + tail->transactionString());
        tail = tail->getNext();
    }
}

int BlockList::getBalanceOf(string name, int initial_balance){
    int bal_diff = 0;
    BlockNode* tmp = head;
    while(tmp != NULL){
        Node* tmp2 = tmp->getHead();
        while(tmp2 != NULL){
            if(tmp2->getFrom() == name) bal_diff -= tmp2->getAmount();
            if(tmp2->getTo()== name) bal_diff += tmp2->getAmount();
            tmp2 = tmp2->getNext();
        }
        tmp = tmp->getNext();
    }
    return bal_diff + initial_balance;
}

void BlockList::clear(){
    BlockNode *temp = head;
    BlockNode *clr;
    while(temp){
        clr = temp->getNext();
        temp->clear();
        delete temp;
        temp = clr;
    }
    head=NULL;
    tail=NULL;
}

string BlockList::getTailHash()
{
    if(tail == NULL) return "NA";
    else             return tail->getHash();
}