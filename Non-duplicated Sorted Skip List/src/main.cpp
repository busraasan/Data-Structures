/*  @Author
    Student Name:Büşra Asan
    Student ID :150180100
    Date:17/08/2021
*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "SkipList.h"


using namespace std;

int main(int argc, char* argv[]){

    string filename = argv[1];
    ifstream file(filename);
    string line;
    string empty;

    int num = 0;
    int seed = 0;
    getline(file, line);
    istringstream readSeed(line);
    readSeed >> empty >> seed;

    int maxHeight = 0;
    getline(file, line);
    istringstream readHeight(line);
    readHeight >> empty >> maxHeight;

    SkipList skipList(maxHeight, seed);
    while(getline(file,line)){
        istringstream iss(line);
        string command;
        int number;
        iss >> command;
        if(command == "LIST"){
        }else if(command == "ADD"){
            while(iss >> num){
                skipList.add(num);
            }
        }else if(command == "DEL"){
            while(iss >> num){
                skipList.remove(num);
            }
        }
        else if(command == "PRINT"){
            skipList.print();
        } else if(command == "CLEAR"){
            skipList.clear();
        } else if(command == "CONTAINS"){
            while(iss >> num){
                bool contains = skipList.contains(num);
                if(contains == true){
                    cout << num << " IN ";
                } else {
                    cout << num << " OUT ";
                }
            }
        }
        else{
            std::cout << "unknown command: " << command << "\n";
        }
    }
    return 0;

}