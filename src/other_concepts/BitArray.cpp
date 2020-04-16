#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned int N, S, P, Q;
    unsigned int i, a;

    vector<bool> integers;        // placed in boolean due to optimization
    integers.resize(0x80000000);  // initialize all array with "false";

    scanf("%u %u %u %u", &N, &S, &P, &Q);

    int nb = 0;
    i = 0;
    a = S % 0x80000000;
    do {
        //cout << a << endl;
        // if never counted
        if (! integers[a]) {
            ++nb;
            integers[a] = true;
        }
        a = (a * P + Q) % 0x80000000;
    } while (++i < N);
    cout << nb << endl;

    return 0;
}