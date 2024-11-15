#include "Car.h"
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void display();

int main() {
    deque<Car> queue;
    for(int i = 0;i < 2; i++) {
    queue.push_back(Car());
    }

    cout << "Initial queue:" << endl;
}