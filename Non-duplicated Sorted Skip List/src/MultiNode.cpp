/*  @Author
    Student Name:Büşra Asan
    Student ID :150180100
    Date:17/08/2021
*/

#include "MultiNode.h"
#include <cstddef>

MultiNode::MultiNode(int height, int data){
    this->height = height;
    this->data = data;
    next = vector<MultiNode*>(height, NULL);
}
