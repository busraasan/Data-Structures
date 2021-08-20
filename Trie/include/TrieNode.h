/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 05/08/2021 */

#pragma once
#include <string>
#include <vector>

#define N 26

using namespace std;

class TrieNode{
    char data;
    bool isEnd;
    
public:
    TrieNode* children[N];
    vector<int> line;

    TrieNode(char data='\0');

    void insert(string, TrieNode*, int);
    TrieNode* search(string);
    bool isEmpty();
    void remove(string);
    void clear();

    char getData(){return data;}
    bool getIsEnd(){return isEnd;}
    void setIsEnd(bool value){this->isEnd = value;}
    void setData(char data){this->data = data;}
    vector<int> getLine(){return line;}
};