/*  @Author
    Student Name:Büşra Asan
    Student ID :150180100
    Date:17/08/2021
*/

#include "SkipList.h"
#include "MultiNode.h"
#include <climits>
#include <stdlib.h>
#include <iostream>


SkipList::SkipList(int maxHeight, int seed){
    this->maxHeight = maxHeight;
    this->seed = seed;
    srand(seed);

    start = new MultiNode(maxHeight, INT_MIN);
    end = new MultiNode(maxHeight, INT_MAX);
    for(int i = 0; i < maxHeight; i++){
        start->setNext(i, end);
    }
}

void SkipList::add(int data){
    if(contains(data)){ //if duplicate don't add new data
        return;
    }
    int height = (rand() % this->maxHeight) + 1;
    MultiNode* newMultiNode = new MultiNode(height, data);
    MultiNode* startTemp = this->start;
    int currHeight = height;

    while(data != startTemp->getNexti(currHeight-1)->getData()){
        while(currHeight > 0){
            if(startTemp->getNexti(currHeight-1)->getData() < data){
                //shift start multinode to right
                startTemp = startTemp->getNexti(currHeight-1);
                break;
            } else{
                //go down one level in the current multinode
                newMultiNode->setNext(currHeight-1, startTemp->getNexti(currHeight-1));
                startTemp->setNext(currHeight-1, newMultiNode);
                currHeight -= 1;
            }
        }
        if(currHeight == 0){
            break;
        }
    }
}

bool SkipList::contains(int data){
    MultiNode* temp = this->start;

    while(temp != end){
        if(temp->getData() == data){
            return true;
        }
        temp = temp->getNexti(0);
    }
    return false;
}

void SkipList::print(){
    for(int i = 0; i < this->maxHeight; i++){
        MultiNode* current = start;
        cout << "L" << i << ": ";
        while(current->getNexti(i) != end){
            current = current->getNexti(i);
            cout << current->getData() << " ";
        }
    }
}

void SkipList::remove(int data){
     for(int i = 0; i < this->maxHeight; i++){
        MultiNode* current = start;
        while(current->getNexti(0) != NULL && current->getNexti(i)->getData() != data){
            current = current->getNexti(i);
        }
        if(current == end){
            continue;
        }
        current->setNext(i, current->getNexti(i)->getNexti(i));
    }
}


void SkipList::clear(){
    MultiNode* temp = this->start->getNexti(0);

    while(temp != end){
        MultiNode* temp2 = temp->getNexti(0);
        delete temp;
        temp = temp2;
    }
    for(int i = 0; i < maxHeight; i++){
        start->setNext(i, end);
    }
}

SkipList::~SkipList(){
    delete start;
    delete end;
}