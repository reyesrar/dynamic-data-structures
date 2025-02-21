#include<iostream>
#include "./queue/queue.h"

struct Person {
    string name;
    int age;
    double weight;

    Person() : name(""), age(0), weight(0.0) {} // Default constructor
    Person(string name, int age, double weight) : name(name), age(age), weight(weight) {}
};

using namespace std;

int main(){
    Queue<Person> queue = Queue<Person>(nullptr);

    queue.push(Person("Gabriel", 24, 65.5));
    queue.push(Person("Mariana", 25, 70.2));
    queue.push(Person("Jose", 22, 68.0));

    queue.printByAge();
    
    return 0;
}