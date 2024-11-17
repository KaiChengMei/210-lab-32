#include "Car.h"
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <array>
using namespace std;

const int lanecount = 4;
const int endtime = 20;
const int pay = 46;
const int join = 39;
const int switchs = 15;

// print 
void display(const array<deque<Car>, lanecount> lanes) {
    for (int i = 0; i < lanecount; i++) {
        cout << "Lane " << i+1 << " Queue: ";
        if (lanes[i].empty()) {
            cout << "Empty";
        } else {
            cout << endl;
            for (const auto& car : lanes[i]) {
                car.print();
            }
        }
    }
}

int main() {

    array<deque<Car>,lanecount> lanes;

    // initial 
    int numcar;
    for(auto& lane : lanes) {
        numcar = rand() % 3 + 1;
        for(int i = 0; i < numcar; i++) {
        lane.push_back(Car());
        }
    }
    cout << "Initial queue:" << endl;
    display(lanes);
    cout << endl;

    for( int time = 1; time <= endtime; time++) {
        cout << endl;
        cout << "Time " << time << endl;

        for ( int a = 0; a < lanecount; a++) {
            auto& lane = lanes[a];

            if (!lane.empty()) {
                int random = rand() % 100;

                // 46% probability that the car at the head of the queue pays its toll and leaves the queue
                if (random < pay) {
                    cout << "Lane " << a+1 << " paid: ";
                    lane.front().print();
                    lane.pop_front();
                } 
                // 39% probability that another car joins the queue
                else if (random < pay+join ){
                    Car newCar;
                    cout << "Lane " << a+1 << " joined: ";
                    newCar.print();
                    lane.push_back(newCar);
                }
                // 15% probability that the rear car will shift lanes
                else if (random < pay+join+switchs ) {
                    // choose the new lane except the origin lane
                    int newlane = 0;
                    while (newlane == (a+1)) {
                        newlane = rand() % lanecount;
                    }

                    cout << "Lane " << (a+1) << " switched: ";
                    lane.back().print();
                    lanes[newlane].push_back(lane.back());
                    lane.pop_back();
                }
            }

            // if lane empty 50/50 a new car enters the queue or not
            else if (rand() % 2 == 0) {
                Car newCar;
                cout << "Lane " << a+1 << " joined: ";
                newCar.print();
                lane.push_back(newCar);
            }

        }

        // print every end of the time
        display(lanes);
        cout << endl;
        
    }
    return 0;
}