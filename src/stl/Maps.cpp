#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
    int queries = 0;
    cin >> queries;
    map<string,int> students;
    for(int i=0;i<queries;i++){
        int query, grade;
        string student;
        cin >> query;
        if(query==1) {
            cin >> student >> grade;
            students[student]+=grade;
        }

        if(query==2) {
            cin >> student;
            students.erase(student);
        }

        if(query==3){
            cin >> student;
            cout << students[student] << endl;
        }
    }  
    return 0;
}
