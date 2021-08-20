#include <functional>
#include <iostream>
#include <math.h>
#include "../include/Heap.h"

/* @Author
Student Name:Büşra Asan
Student ID :150180100
Date:10/08/2021*/

using namespace std;

void Heap::sort(std::function<int(int,int)> minmax){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if (!minmax(arr[j], arr[j+1])){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

Heap::Heap(int capacity, std::function<int(int,int)> minmax){
    this->capacity = capacity;
    this->size = 0;
    this->minmax = minmax;
    this->arr = new int[capacity];
}

void Heap::heapification(int *arrto, int node, bool isDown){ 
    if(isDown){
        int toChange = node;
        bool changed = false;
        int l = 2 * node + 1;
        int r = 2 * node + 2;
    
        if (r < size && minmax(arrto[r],arrto[toChange])){
            toChange = r;
            changed = true;
        }
    
        if (l < size && minmax(arrto[l],arrto[toChange])){
            if(changed){
                if(minmax(arrto[l], arrto[r])){
                    toChange = l;
                }
            } else {
                toChange = l;
            }
        }
    
        if (toChange != node) {
            int temp = arrto[node];
            arrto[node] = arrto[toChange];
            arrto[toChange] = temp;
            heapification(arrto, toChange, true);
        }
    } else {
        int parent = (node-1)/2;
        if(arrto[parent] > 0){
            if(minmax(arrto[node], arrto[parent])){
                int temp = arrto[node];
                arrto[node] = arrto[parent];
                arrto[parent] = temp;
                heapification(arrto, parent, false);
            }  
        }
    }
    
}

void Heap::add(int toAdd){
    size += 1;
    arr[size-1] = toAdd;
    if(size != 1){
        heapification(arr, size-1, false);
    }
}

void Heap::remove(int toRemove){
    int index = 0;
    int lastElement = arr[size-1];
    bool found = false;
    for(int i = size-1; i >= 0; i--){
        if(arr[i] == toRemove){
            index = i;
            found = true;
        }
    }
    if(found){
        arr[size-1] = arr[index];
        arr[index] = lastElement;
        size--;
        if(index==0){
            heapification(arr, index, true);
        } else if(index > 0 && index < pow(2,log2(size))-1){
            heapification(arr,index, false);
            heapification(arr, index, true);
        } else {
            heapification(arr, index, false);
        }
    }
}

void Heap::heapPrint(){
    if(size != 0){
        int depth = log2(size);
        int count = 0;
        for(int i = 0; i < depth; i++){
            for(int j = 0; j < pow(2,i); j++){
                cout << arr[count] << " ";
                count += 1;
            }
        }
        for(int i = pow(2,depth)-1; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void Heap::sortedPrint(){
    sort(minmax);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void Heap::setArray(int* b, int size){
    delete [] arr;
    arr = b;
    this->size = size;
}

Heap::~Heap(){
    delete [] arr;
}