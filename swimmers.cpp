//
// Created by Sg on 08.08.2022.
//
#include <thread>
#include <iostream>
#include "swimmers.h"
using namespace std;
std::multimap<int, std::string> result;
void swim (const Swimmer& myS, int distance)
{
    int way = myS.speed;
    int sec = 1;

    while(distance > way)
    {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Swimmer " << myS.name << " swam " << way << " meters" << endl;
        way += myS.speed;
        sec++;
    }

    cout << "Swimmer " << myS.name << " finished! " << endl;

    result_access.lock();
    result.insert(Int_Pair (sec, myS.name));
    result_access.unlock();
}
/*template<typename T>
void enterValue(T &n, T min, T max)
{
    n = max / 2;
    do
    {
        if(!cin || (n < min || n > max))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "-------------------Error----------------\n";
            cout << min << " <= number diapason <= " << max;
            cout << "\n-----------------------------------------\n";
            cout << "Repeat enter:";
        }

        cin>>n;
    }
    while(!cin || (n < min || n > max));
}*/