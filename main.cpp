#include "Car.h"
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <array>
using namespace std;

const int lanecount;
const int endtime;
const int pay;
const int join;
const int switchs;

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
        cout << "Time " << time << endl;

        for ( int a = 0; a < lanecount; a++) {
            int random = rand() % 100;

            // 46% probability that the car at the head of the queue pays its toll and leaves the queue
            if (random < pay) {
                cout << "Lane " << a+1 << " paid: ";
                lanes[a].front().print();
                lanes[a].pop_front();
            } 
            // 39% probability that another car joins the queue
            else if (random < pay+join ){
                Car newCar;
                cout << "Lane " << a+1 << " lane: ";
                newCar.print();
                lanes[a].push_back(newCar);
            }
            // 15% probability that the rear car will shift lanes
            else if (random < pay+join+switchs ) {
                // choose the new lane except the origin lane
                int newlane = 0;
                while (newlane = (a+1)) {
                    newlane = rand() % lanecount;
                }

                cout << "Lane " << (a+1) << " switched: ";
                lanes[a].back.print();
                lanes[newlane].push_back(lanes[a].back());
                lanes[a]pop_back();
            }

        }

        // print every end of the time
        display(Cqueue);
        cout << endl;
        time++;
    }
    return 0;
}