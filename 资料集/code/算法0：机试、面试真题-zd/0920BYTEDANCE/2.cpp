#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int64_t a, b, res;
        char c;
        cin >> a >> b >> c;
        switch(c){
            case '+':
                res = ((a%1000000007) + (b%1000000007)) % 1000000007;
                break;
            case '-':
                res = (a-b);
                break;
            case '*':
                res = ((a%1000000007) * (b%1000000007)) % 1000000007;
                break;
            case '^':
                res = 1;
                while(b != 0) {
                    if(b % 2 == 1)
                        res = ((res%1000000007) * (a%1000000007)) % 1000000007;
                    a = ((a%1000000007) * (a%1000000007)) % 1000000007;
                    b /= 2;
                }
                break;
        }
        cout << res << endl;
    }
    return 0;
}