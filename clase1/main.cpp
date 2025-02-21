#include <iostream>
#include "./simpleList/simpleList.h"

using namespace std;

int main(){

    List<int> simpleList = List<int>(nullptr);
    simpleList.insert(10);
    simpleList.insert(6);
    simpleList.insert(12);
    
    simpleList.update(6, 11);

    simpleList.print();

    return 0;    

}