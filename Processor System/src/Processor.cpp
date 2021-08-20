#include "../include/Processor.h"
#include <iostream>

/* @Author
Student Name: Busra Asan
Student ID: 150180100
Date: 16-07-2021 */

using namespace std;

Processor::Processor(int mips, int threshold){
    this->MIPS = mips;
    if(MIPS%threshold == 0){
        this->maxRunning = MIPS/threshold - 1;
    } else {
        this->maxRunning = MIPS/threshold;
    }   
    this->threshold = threshold;
}

void Processor::addJob(Job toAdd){
    incomingJobs.push(toAdd);
}

void Processor::step(int time){
    int currentRunning = runningJobs.size();
    //First execute the processes if running jobs are not empty
    if(!runningJobs.empty()){
        for(int i = 0; i < runningJobs.size(); i++){
            runningJobs[i].setMI(runningJobs[i].getMI() - MIPS/runningJobs.size());
        }
        //after execution check whether there is a process that ends, if there is remove it
        //and add it to the finished jobs' list.
        for(int k = 0; k < currentRunning; k++){
            if(runningJobs[k].getMI() <= 0){
                runningJobs[k].setFinish(time);
                finishedJobs.push_back(runningJobs[k]);
                runningJobs.erase(runningJobs.begin() + k);
            }
        }
    }
    //if there is place available add process from incomingjobs list.
    //in the while loop we check for each process there is a portion of MIPS bigger than threshold
    //after adding a new process to running jobs. If it is and incoming jobs are not empty,
    //we take the process into running ones and run it
    while(MIPS/(runningJobs.size()+1) > threshold && !incomingJobs.empty()){
            incomingJobs.front().setStart(time);
            runningJobs.push_back(incomingJobs.front());
            incomingJobs.pop();
    }
}

void Processor::printQ(){
    queue<Job> temp;
    temp = incomingJobs;
    while(!temp.empty()){
        cout << temp.front().getID() << " ";
        temp.pop();
    }    
}

void Processor::print(int id){
    string flag;
    int start;
    int finish;
    //check every list to find the process that has the id. According to where it is found update flag.
    for(int i = 0; i < finishedJobs.size(); i++){
        if(finishedJobs[i].getID() == id){
            flag = "F";
            start = finishedJobs[i].getStart();
            finish = finishedJobs[i].getFinish();
        }
    }
    for(int j = 0; j < runningJobs.size(); j++){
        if(runningJobs[j].getID() == id){
            flag = "R";
            start = runningJobs[j].getStart();
            finish = runningJobs[j].getFinish();
        }
    }
    queue<Job> temp;
    temp = incomingJobs;
    while(!temp.empty()){
        if(temp.front().getID() == id){
            flag = "W";
            start = -1;
            finish = -1;
        }
        temp.pop();
    }
    cout << flag << " " << start << " " << finish << " ";
}