#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--){
        int i;
        cin >> i;
        cout << int(log(i)/log(2))+1 << endl;
    }
    return 0;
}