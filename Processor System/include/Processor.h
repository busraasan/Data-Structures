#include "Job.h"
#include <queue>

using namespace std;

/* @Author
Student Name: Busra Asan
Student ID: 150180100
Date: 16-07-2021 */

class Processor{
    queue<Job> incomingJobs;
    vector<Job> runningJobs;
    vector<Job> finishedJobs;
    /*Job* incomingJobs;
    int front, back, numOfElements, capacity;
    Job* finishedJobs;
    Job* runningJobs;
    int sizeOfRunningJobs, sizeOfFinishedJobs;*/
    int MIPS; //can execute in a second
    int maxRunning;
    int threshold;
public:
    Processor(int, int);
    void addJob(Job);
    void step(int);
    void print(int);
    void printQ();
};