#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "SimpleList.h"
#include "Node.h""


using namespace std;

#define WASH_TIME 180
#define NULL 0

int main() 
{ 
    srand(time(NULL));
    int washedCars = 0;
    int totalWaitTime = 0;
    int carsWaitingInLine = 0;
    int carWashTimer = 0;
    int totSimTime = 0;         // user input
    int probability = 0;        // user input
    int simTime = 0;
    bool carInWash = false;
    SimpleList sl;

         // User Input
        cout << "Amount of Run time hours: " << endl;
        cin >> totSimTime; 
        totSimTime = totSimTime * 60 * 60;
        cout << "Probability of new car: " << endl;
        cin >> probability;
    
    // Car Wash Loop
    while (simTime < totSimTime) {
        int q = rand() % 100;
        // cars into the queue
        if (q < probability) {
            sl.QueueItem(simTime);                           // Put a car into the waiting line
            carsWaitingInLine = carsWaitingInLine + 1;       // and add it to the amount of cars waiting
        }
        // check if car is washed
        if (carInWash == true && carWashTimer > WASH_TIME) {
            carInWash = false;
            carWashTimer = 0;
        }
        // Wash Timer
        else
        {
            carWashTimer = carWashTimer + 1;       // this keeps track of the car wash timer
        }
        // dequeue car and put in wash
        if (carInWash == false) {
            int localSimTime = sl.DequeueItem();
            if (localSimTime > 0)
            {
                int localWaitTime = simTime - localSimTime;
                totalWaitTime = totalWaitTime + localWaitTime; // This gets amount of time just in waiting line
                carInWash = true;
                washedCars = washedCars + 1;
                carsWaitingInLine--;  // Make sure to take cars out of the waiting line when put into wash
            }
        }
        simTime = simTime + 1;
    }
        cout << "Number of cars washed: " << washedCars << endl;
        cout << "Average wait time: " << totalWaitTime / carsWaitingInLine << endl;
        cout << "Number of cars in line: " << carsWaitingInLine << endl;
}



