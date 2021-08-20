#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../include/Processor.h"

/* @Author
Student Name: Busra Asan
Student ID: 150180100
Date: 16-07-2021 */

using namespace std;

int main(int argc, char* argv[]){
    int MIPS_THRESHOLD = 0;
    string filename = argv[1];
    ifstream file(filename);
    string line;
    int zero, mips, mips_threshold;
    file >> zero >> mips >> mips_threshold;

    MIPS_THRESHOLD = mips_threshold;
    Processor processor(mips, mips_threshold);

    int time = 0;
    while(getline(file, line)){
        istringstream iss(line);
        int jobTime = 0;
        string command;
        iss >> jobTime >> command;
        //update time until the job's time and in every time step execute step which handles everything happens in that time period.
        while(time < jobTime){
            processor.step(time);
            time+=1;
        }
        //time = jobTime now.
        if(command=="JOB"){
            int id, mi;
            iss >> id >> mi;
            Job job(id, mi);
            processor.addJob(job);

        } else if(command=="PRINTQ"){
            cout << "WQ ";
            processor.printQ();
        } else if(command=="PRINT"){
            int id;
            iss >> id;
            processor.print(id);
        }
    }
    return 0;
}