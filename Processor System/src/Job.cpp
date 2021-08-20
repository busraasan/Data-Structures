#include "../include/Job.h"

/* @Author
Student Name: Busra Asan
Student ID: 150180100
Date: 16-07-2021 */

Job::Job(int id, int mi){
    this->ID  = id;
    this->MI = mi;
    this->start = -1;
    this->finish = -1;
}