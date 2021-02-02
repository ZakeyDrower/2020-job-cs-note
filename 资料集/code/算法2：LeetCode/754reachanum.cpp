#include<bits/stdc++.h>
using namespace std;

int reachNumber(int target)
{
    int k = 0;
    target = abs(target);
    while(target > 0){
        k++;
        target -= k;
    }
    while(abs(target)%2 == 1){
        k++;
        target -= k;
    }
    return k;
}


int main()
{
    int i;
    while(cin >> i) cout << reachNumber(i) << endl;
    return 0;
}