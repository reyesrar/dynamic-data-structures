#include <iostream>
#include "./simpleList/simpleList.h"
#include "./circularList/circularList.h"

using namespace std;

int main(){

    /*List<int> simpleList = List<int>(nullptr);
    simpleList.insert(10);
    simpleList.insert(6);
    simpleList.insert(12);
    
    simpleList.update(6, 11);

    simpleList.print();

    return 0;    */

    CircularList<int> circularList = CircularList<int>(nullptr);
    circularList.insert(10);
    circularList.insert(6);
    circularList.insert(12);

    circularList.update(6, 11);

    circularList.print();

    return 0;

}