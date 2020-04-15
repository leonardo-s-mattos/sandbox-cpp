#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <numeric>

class Person{

    protected:
        string name;
        int age;

    public:
        int get_age(){return age;};
        void set_age(int arg){age=arg;};
        string get_name(){return name;};
        void set_name(string arg){name=arg;};
        virtual void getdata(){};
        virtual void putdata(){};
};

class Professor : public Person{

    int publications;
    int cur_id;
    public:
        static int next_id;
        Professor(){
            next_id++;
            cur_id = next_id;
        };
        int get_publications(){return publications;};
        void set_publications(int arg){publications=arg;};
        int get_cur_id(){return cur_id;};
        void set_cur_id(int arg){cur_id=arg;};

        void getdata(){
            cin >> name >> age >> publications;
        };

        void putdata(){
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        };
        
};

class Student: public Person{

    size_t marks[6];
    int cur_id;

    public:
        static int next_id;
        Student(){
            next_id++;
            cur_id = next_id;
        };
        void getdata(){
            cin >> name >> age >> 
            marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
        };

        void putdata(){
            int sum = 0;
            sum = accumulate(marks, marks+6, sum);
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        };
        
};

int Professor::next_id = 0;
int Student::next_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
