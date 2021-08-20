#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include "../include/Heap.h"

/* @Author
Student Name:Büşra Asan
Student ID :150180100
Date:10/08/2021*/

using namespace std;

int smaller(int x, int y){
    return (x < y) ? true : false;
}

int bigger(int x, int y){
    return (x > y) ? true : false;
}

int main(int argc, char* argv[]){

    string filename = argv[1];
    ifstream file(filename);
    string line;
    getline(file,line);
    istringstream heapInitial(line);
    string heapType;
    int capacity = 20;
    heapInitial >> heapType;
    heapInitial >> capacity;
    Heap* heap;
    if(heapType=="MINHEAP"){
        heap = new Heap(capacity, smaller);
    } else {
        heap = new Heap(capacity, bigger);
    }

    int num;
    vector<int> nums;
    int i = 0;
    while(heapInitial >> num){
        nums.push_back(num);
    }
    reverse(nums.begin(), nums.end());
    int *a = new int[capacity];
    for(int i = 0; i < nums.size(); i++){
        a[i] = nums[i];
    }
    
    heap->setArray(a, nums.size());

    for(int i = nums.size()-1; i >= 0; i--){
        heap->heapification(heap->getArr(), i, true);
    }

    while(getline(file,line)){
        istringstream iss(line);
        string command;
        int number;
        iss >> command;
        iss >> number;
        if(command == "ADD"){
            heap->add(number);
        }
        else if(command == "DEL"){
            heap->remove(number);
        }else if(command == "PRINT"){
            heap->heapPrint();
        }else if(command == "SORT"){
            heap->sortedPrint();
        }
        else{
            std::cout << "unknown command: " << command << "\n";
        }
    }
    delete heap;
    return 0;
}