#include <functional>

/* @Author
Student Name:Büşra Asan
Student ID :150180100
Date:10/08/2021*/

using namespace std;

class Heap{
private:
    int capacity;
    int size;
    int* arr;
    std::function<int(int,int)> minmax;
public:
    Heap(int,std::function<int(int,int)>);

    void add(int toAdd);
    void remove(int toRemove);
    void heapification(int*, int, bool);
    void heapPrint();
    void sortedPrint();
    void sort(std::function<int(int,int)> minmax);

    void addToArray(int num);
    void setArray(int* arr, int size);

    int* getArr() const{return arr;}
    int getSize() const{return size;}

    ~Heap();
};