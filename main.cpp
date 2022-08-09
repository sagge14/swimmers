#include <iostream>
#include <thread>
#include "swimmers.h"
using namespace std;

template<typename T>
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
}

int main() {

    const int N = 6;
    const int distance = 100;
    Swimmer mySwimmers[N];
    thread thSwimmers[N];

    for (int i = 0; i < N; ++i) {
        system("cls");
        cout << "---Swimmers---" << endl;
        cout << "Enter name swimmer N " << i + 1 << ":";
        cin >> mySwimmers[i].name;
        cout << "Enter speed swimmer N " << i + 1 << ":";
        enterValue(mySwimmers[i].speed,1,10); //word record 9 km/h
    }
    cout << "-ok, press eny key for start!" << endl;

    system("pause");
    system("cls");

    for (int i = 0; i < N; ++i)
        thSwimmers[i] = thread(swim,mySwimmers[i],distance);
    for (auto & thSwimmer : thSwimmers)
        thSwimmer.join();

    int i = 0;
    int sec = 0;
    system("pause");
    system("cls");
    cout <<"---Result---" << endl;
    for(const auto& elem : result)
    {
        if(sec!=elem.first)
        {
            sec =elem.first;
            i++;
        }
        cout << "N " << i << " " << elem.second << " " << elem.first << " sec." << "\n";
    }

    system("pause");
    return 0;
}
