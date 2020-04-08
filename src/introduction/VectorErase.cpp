#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;
    vector<int> numbers;

    int count = 0;
    
    while(count<n){
        int number;
        cin >> number;
        numbers.push_back(number);
        count++;
    }

    int positionToErase;
    int intervalBegin, intervalEnd;
    scanf ("%i",&positionToErase);
    scanf ("%i %i",&intervalBegin, &intervalEnd);

    numbers.erase(numbers.begin() + positionToErase-1);
    
    numbers.erase(numbers.begin() + intervalBegin-1, numbers.begin() + intervalEnd-1);
    cout << numbers.size() << endl;
    for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << " ";
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
