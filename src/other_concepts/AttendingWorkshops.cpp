#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshops{

    int start_time_;
    int duration_;
    int end_time_;
        
};

struct Available_Workshops{
    int n;
    Workshops* workshops_ = new  Workshops[n];
};


//Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
