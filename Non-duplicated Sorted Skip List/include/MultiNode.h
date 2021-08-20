/*  @Author
    Student Name:Büşra Asan
    Student ID :150180100
    Date:17/08/2021
*/

#pragma once
#include <vector>

using namespace std;

class MultiNode{
private:
    int height;
    int data;
    vector<MultiNode*> next;

public:
    MultiNode(int height, int data);
    vector<MultiNode*> getNext(){return next;}
    MultiNode* getNexti(int i){return next[i];}
    void setNext(int i, MultiNode* target ){this->next[i] = target;}
    int getData(){return data;}
    int getHeight(){return height;}
};