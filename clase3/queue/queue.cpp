#include<iostream>
#include "./queue/queue.h"

using namespace std;

int main(){
    Queue<int> queue = Queue<int>(nullptr);
    queue.push(5);
    queue.push(6);
    queue.push(8);
    queue.push(1);
    queue.push(3);

    queue.pop();

    cout<<endl;
    queue.push(9);
    queue.push(2);
    queue.print();
}