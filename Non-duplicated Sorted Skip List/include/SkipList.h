
/*  @Author
    Student Name:Büşra Asan
    Student ID :150180100
    Date:17/08/2021
*/

#pragma once
#include "MultiNode.h"

using namespace std;

class SkipList{
    MultiNode* start;
    MultiNode* end;
    int maxHeight;
    int seed;
public:
    SkipList(int maxHeight, int seed);
    void add(int value);
    void remove(int value);
    void print();
    void clear();
    bool contains(int data);
    ~SkipList();
};
