#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i =0; i<n; i++) {
        cin >> numbers[i];
    }

    cin >> n;
    vector<int>::iterator it;
    int query;
    for(int j=0;j<n;j++){
        cin >> query;
        it = lower_bound (numbers.begin(), numbers.end(), query);
        
        if (it != numbers.end() && *it == query) {
            cout << "Yes " << distance(numbers.begin(), it)+1 << '\n';
        } else{
            cout << "No " << distance(numbers.begin(), it)+1 << '\n';
        }
    }

    return 0;
}
