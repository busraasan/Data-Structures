/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 27/07/2021 */

#pragma once
#include <string>
using namespace std;

class Node{
    string from;
    string to;
    int amount;
    Node* next = NULL;
public:
    Node(string from="", string to="", int amount=0){this->from = from, this->amount = amount, this->to = to;}
    string getFrom(){return from;}
    string getTo(){return to;}
    int getAmount(){return amount;}
    Node* getNext(){return next;}
    void setNext(Node* next){this->next=next;}
};