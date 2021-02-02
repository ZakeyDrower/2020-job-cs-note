#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int temp;
        cin >> temp;
        int res = 0;
        int flag = 0;
        while (temp > 0)
        {
            int n = temp % 10;
            temp = temp / 10;
            int temp_div = temp;
            while(temp_div > 0 && n != 9)
            {
                if(temp_div % 10 > 0)
                {
                    flag = 1;
                    break;
                }
                temp_div = temp_div / 10;
            }
            if(flag == 1)
                --temp;
            if(flag == 1 && n != 9)
            {
                res += (10 + n);
            }
            else
            {
                res += n;
            }
            flag = 0;
        }
        cout << res << endl;
    }
    return 0;
}