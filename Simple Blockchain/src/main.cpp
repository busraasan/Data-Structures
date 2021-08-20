/* @Author
Student Name: Büşra Asan
Student ID : 150180100
Date: 27/07/2021 */

#include "md5.h"
#include "BlockNode.h"
#include "BlockList.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

void sort_users(string name_arr[], int balance_arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(name_arr[j] > name_arr[j+1]){
                string temp_name = name_arr[j];
                int temp_balance = balance_arr[j];
                name_arr[j] = name_arr[j+1];
                balance_arr[j] = balance_arr[j+1];
                name_arr[j+1] = temp_name;
                balance_arr[j+1] = temp_balance;
            }
        }
    }
}

int main(int argc, char* argv[]){
    string filename = argv[1];
    ifstream file(filename);
    string line;
    getline(file,line);
    istringstream blocknodes(line);
    string name;
    int balance;
    string name_arr[2000];
    int balance_arr[2000];
    BlockList blockList;
    int i = 0;
    while(blocknodes >> name >> balance){
        name_arr[i] = name;
        balance_arr[i] = balance;
        i++;
    }
    sort_users(name_arr, balance_arr, i);
    while(getline(file,line)){
        istringstream iss(line);
        string command;
        iss >> command;
        if(command == "BLOCK"){
            string from, to;
            int amount;
            BlockNode* newBlock = new BlockNode;
            while(iss >> from >> to >> amount){
                Node* transaction = new Node(from, to, amount);
                newBlock->addTransaction(transaction);
            }
            blockList.addBlockNode(newBlock);
        }
        else if(command == "BALANCE"){
            for(int j=0; j < i; j++){
                cout << name_arr[j] << ":" << blockList.getBalanceOf(name_arr[j], balance_arr[j]) << " ";
            }
        }else if(command == "CLEAR"){
            blockList.clear();
        }else if(command == "PRINT"){
            std::cout << blockList.getTailHash() << " ";
        }
        else{
            std::cout << "unknown command: " << command << "\n";
        }
    }
    blockList.clear();
    return 0;
}