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

    sort(numbers.begin(), numbers.end());

    for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << " ";
    }
    return 0;
}

