#include "Car.h"
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <array>
using namespace std;

const int lanecount;
const int endtime;

// print 
void display(const array<deque<Car>, lanecount> lanes) {
    for (int i = 0; i < lanecount; i++) {
        cout << "Lane " << i+1 << " Queue: ";
        if (lanes[i].empty()) {
            cout << "Empty";
        } else {
            cout << endl;
            for (const auto car : lanes[i]) {
                car.print();
            }
        }
    }
}

int main() {

    array<deque<Car>,lanecount> lanes;

    // initial 
    int numcar;
    for(auto lane ; lanes) {
        numcar = rand() % 3 + 1;
        for(int i = 0; i < numcar; i++) {
        lanecount.push_back(Car());
        }
    }
    cout << "Initial queue:" << endl;
    display(lanes);
    cout << endl;

    int time=1;
    for( int time = 1; time <= endtime; time++) {
        cout << "Time " << time << " operation: ";
        // 55% probability that the car at the head of the line pays its toll and leaves the toll booth

        if (rand() % 100 < 55) {
            cout << "Car paid: ";
            Cqueue.front().print();
            Cqueue.pop_front();
        } 
        // 45% probability that another car joins the line for the toll booth
        else {
            Car newCar;
            cout << "Joined lane: ";
            newCar.print();
            Cqueue.push_back(newCar);
        }
        cout << "Queue:" << endl;

        // print every end of the time
        display(Cqueue);
        cout << endl;
        time++;
    }
    return 0;
}