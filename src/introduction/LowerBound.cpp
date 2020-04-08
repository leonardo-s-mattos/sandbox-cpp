#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> numbers(n);

    int count = 0;
    while(count<n){
        cin >> numbers[count];
        count++;
    }

    int q;
    cin >> q;
    vector<int> queries(q);

    count = 0;
    while(count<q){
        cin >> queries[count];   
        count++;
    }

    vector<int>::iterator it;
    for(int j=0;j<queries.size();j++){
        it = find (numbers.begin(), numbers.end(), queries[j]);
        if (it != numbers.end()){
            cout << "Yes " << distance(numbers.begin(), it)+1 << '\n';
        } else{
            vector<int>::iterator low;
            low = lower_bound (numbers.begin(), numbers.end(), queries[j]);
            cout << "No " << distance(numbers.begin(), low)+1 << '\n';
        }
    }

    return 0;
}
