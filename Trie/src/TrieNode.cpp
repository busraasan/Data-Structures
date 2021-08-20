
/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 05/08/2021 */

#include "../include/TrieNode.h"
#include <iostream>

using namespace std;

int count = 0;

TrieNode::TrieNode(char data){
    this->data = data;
    this->isEnd = false;
    for(int i = 0; i < N; i++){
        children[i] = nullptr;
    }
}

void TrieNode::insert(string word, TrieNode* node, int lineCount){
    /* We check the given node's letter corresponds to the word[0]. In every recursive iteration we cut a letter from the word so we can continue to
    add the word from the necessary location if we have some part of the word in the tree.
    */
    int alphabetID = word[0] - 'a';
    if(word.length() == 0){
        node->setIsEnd(true);
        node->line.push_back(lineCount);
        return;
    } else if(count == 0 && search(word) != NULL && !search(word)->line.empty() && search(word)->line.front() != -1){
        search(word)->line.push_back(lineCount);
        return;
    }
    count++;

    if(node->children[alphabetID] == NULL){
        node->children[alphabetID] = new TrieNode(word[0]);
    }
    node = node->children[alphabetID];
    insert(word.substr(1, word.length()-1), node, lineCount);
    count = 0;
}

TrieNode* TrieNode::search(string word){
    bool empty = isEmpty();
    if(empty){
        return NULL;
    } else {
        TrieNode* temp = this;
        /*we are iterating through each element for each letter in word consecutively. If we fail to find some letter we return NULL.
        if we find all the letters in the word after the for loop we check whether the place we get is an leaf node (indicated by isEnd variable in the TrieNode)
        if we are at the end of a word then we return that leaf node, otherwise NULL.*/
        for(int i = 0; i < word.length(); i++){
            int alphabetID = word[i] - 'a';
            if(temp->children[alphabetID] == NULL){
                return NULL;
            } else {
                temp = temp->children[alphabetID];
            }
        }
        if(temp->getIsEnd()){
            return temp;
        }
        else
            return NULL;
    }
}

bool TrieNode::isEmpty(){
    bool empty = true;
    for(int i = 0; i < N; i++){
        if(this->children[i] != NULL){
            empty = false;
            return empty;
        }
    }
    return empty;
}

void TrieNode::clear(){
    TrieNode* node = this;
    for(int i = 0; i < N; i++){
        if(node->children[i] != NULL){
            node->children[i]->clear(); 
        }
    }
    delete node;
}