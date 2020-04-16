#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshops{

    Workshops(){};
    Workshops(int start_time, int duration):start_time_(start_time), duration_(duration), end_time_(start_time+duration){};
    int start_time_;
    int duration_;
    int end_time_;

    bool operator<(const Workshops& o) const
    {
        return end_time_ < o.end_time_;
    }
        
};

struct Available_Workshops{

    Available_Workshops(int n):n_(n), workshops_(new  Workshops[n]){}
    int n_;
    Workshops* workshops_ ;
};


//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_times[], int duration[], int number_of_workshops){

    Available_Workshops* ws = new Available_Workshops(number_of_workshops);
    for(int i=0;i<number_of_workshops;i++){
        ws->workshops_[i] = Workshops(start_times[i], duration[i]);
    }

    return ws;
};

int CalculateMaxWorkshops(Available_Workshops* ws){
    int result = 0;
    sort(ws->workshops_, ws->workshops_+ws->n_);

    int time_right_now = -1;
    for(int i=0;i<ws->n_;i++){
        if(time_right_now <= ws->workshops_[i].start_time_){
            time_right_now = ws->workshops_[i].end_time_;
            result++;
        }
    }

    return result;
}

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
