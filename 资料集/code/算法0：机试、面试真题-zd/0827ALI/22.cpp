#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, x, y;
    int T, n, m;
    int ans, left;
    int ans1, left1; //能杀的人数和剩余的血量(分两种情况）
    int a[100000];
    int b[100000];
    int hasWaponCnt, noWaponCnt; //有装备和没有装备掉落的怪物数量
    int sword;      //记录刀的数量

    cin >> T;
    while(T--) {
        cin >> n >> m;
        hasWaponCnt = noWaponCnt = sword = 0;
        for (i = 1; i <= n; i++)
        {
            cin >> x >> y;
            if (y != 0) {
                sword += y;
                a[hasWaponCnt++] = x;
            }
            else
                b[noWaponCnt++] = x;
        }
        sort(a, a + hasWaponCnt);
        sort(b, b + noWaponCnt);
        //only kill with wapon
        i = 0;
        ans = 0;
        left = m;
        while (left >= 0 && i < noWaponCnt) {
            if (left >= b[i]) {
                left -= b[i++];
                ans++;
            }
            else
                break;
        }
        if (m >= a[0])
        {
            if (sword >= n - 1)
            {
                if (ans < n)
                {
                    ans = n;
                    left = m - a[0];
                }
                else if (ans == n && left < m - a[0])
                    left = m - a[0];
                cout << ans << ' ' << m - left << endl;
                continue;
            }
            int k = n - 1 - sword;

            int *temp = new int[k];
            x = 1;
            y = 0;
            i = 0;
            a[hasWaponCnt] = b[noWaponCnt] = 100000000;
            while (i < k)
            {
                if (a[x] < b[y])
                    temp[i] = a[x++];
                else
                    temp[i] = b[y++];
                i++;
            }
            i = 0;
            ans1 = 1 + sword;
            left1 = m - a[0];
            while (i < k && left1 >= 0)
            {
                if (ans1 == n)
                    break;
                if (left1 >= temp[i])
                {
                    left1 -= temp[i++];
                    ans1++;
                }
                else
                    break;
            }
            if (ans1 > ans)
            {
                ans = ans1;
                left = left1;
            }
            else if (ans1 == ans && left < left1)
                left = left1;
            delete[] temp;
        }
        cout << ans << ' ' << m - left << endl;
    }

    return 0;
}

/*

2
3 5
4 1
5 1
7 7
2 1
2 2
4 0

*/