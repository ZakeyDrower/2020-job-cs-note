#include<bits/stdc++.h>
using namespace std;


int countZeroinBinary(int n) {
    int ctr = 0;
    for(int i = 1; i <= n; ++ i) {
        while(i % 2 == 0){
            ++ ctr;
            i /= 2;
        }
    }
    return ctr;
}

 