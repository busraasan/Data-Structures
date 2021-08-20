/* @Author
Student Name: Busra Asan
Student ID: 150180100
Date: 16-07-2021 */

class Job{
    int ID;
    int MI; //required by the job
    int start;
    int finish;
public:
    Job(int id=0, int mi=0);
    int getID() const{return ID;};
    int getMI() const{return MI;};
    int getStart() const{return start;};
    int getFinish() const{return finish;};
    void setStart(int start){this->start = start;};
    void setFinish(int finish){this->finish = finish;};
    void setMI(int mi){this->MI = mi;};
};