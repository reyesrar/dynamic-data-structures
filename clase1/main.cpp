#include <iostream>
#include "./simpleList/simpleList.h"

using namespace std;

int main(){

    List<int> simpleList = List<int>(nullptr);
    simpleList.insert(2);
    simpleList.insert(4);
    simpleList.insert(8);
    
    simpleList.print();

    return 0;    

}