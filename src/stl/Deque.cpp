#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

int max_number_from_range(int arr[], int begin, int end){
    int maxNumber=0;
    for (int g = begin; g<=end;g++){
       // cout << arr[g] << " ";
        if(arr[g] > maxNumber) {
            maxNumber = arr[g];
        }
    }
    //cout << endl;
    return maxNumber;
}

void printKMax(int arr[], int n, int k){
    
   deque<int> q;
    for(int i = 0; i < n; i++)
    {
        //cout << "at position " << i << endl;
        for(;!q.empty() && arr[i] > q.back();){
            //cout << "pop back at position " << i << " " << arr[i] << " >" << q.back() << endl;
            q.pop_back();  
        }
        //cout << "push back at position " << i << " " << arr[i] << endl;
        q.push_back(arr[i]);  
        if(i >= k && q.front() == arr[i-k]){
            //cout << "pop front at position (i>=k)" << i << " " << arr[i-k] << endl;
            q.pop_front();  
        }
        if(i >= k-1)
            printf(i < n-1 ? "%d ":"%d\n", q.front());
    }
    

}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}