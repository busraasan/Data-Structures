/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 05/08/2021 */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../include/TrieNode.h"

using namespace std;

int main(int argc, char* argv[]){
    TrieNode* trie = new TrieNode;
    vector<string> wordList;

    string filename = argv[1];
    ifstream file(filename);
    string line;
    int lineCount = 1;
    while(getline(file, line)){
        istringstream iss(line);
        string word;
        while(iss >> word){
            string s_low="";
            for(char c:word){
                if(tolower(c)<'a' || tolower(c)>'z' )
                    continue;
                else s_low+=tolower(c);
            }
            if(s_low.length()==0){
                continue;
            } else {
                trie->insert(s_low, trie, lineCount);
            }
        }
        lineCount++;
    }
    
    for(int i = 2; i < argc; i++){
        cout << argv[i] << ":";
        
        TrieNode* temp = trie->search(argv[i]);
        if(temp == NULL){
            cout << -1 << " ";
        } else {
            for(int j = 0; j < temp->getLine().size(); j++){
                cout << temp->getLine()[j] << " ";
            }
        }
    }
    trie->clear();
    return 0;
}