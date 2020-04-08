#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    vector<int> inputs;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int c;
    while ( iss >> c) {    
        inputs.push_back(c);
    }
    n = inputs[0];
    q = inputs[1];
    
    vector<vector<int>> sequencies;
    for(int i=0;i<n;i++){   
        vector<int> result;
        string sequence;
        getline(cin, sequence);
        
        istringstream issSequence(sequence);
        int number;
        while ( issSequence >> number) {    
            result.push_back(number);
        }
        sequencies.push_back(result);
    }
    

    vector<vector<int>> pairs;
    for(int i=0;i<n;i++){
        vector<int> result;
        string pair;
        getline(cin, pair);
        istringstream issPair(pair);
        int number;
        while ( issPair >> number) {    
            result.push_back(number);
        }
        pairs.push_back(result);
    }

    for(int i =0;i<pairs.size();i++){
        int sequence = pairs[i][0];
        int position = pairs[i][1];
        cout << sequencies[sequence][position+1] << endl;
    }
    return 0;

}


