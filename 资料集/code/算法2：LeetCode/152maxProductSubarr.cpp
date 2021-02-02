#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> arr)
{
    int res = arr[0];
    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int cax = max*arr[i];
        int cin = min*arr[i];
        max = std::max(std::max(cax, cin), arr[i]);
        min = std::min(std::min(cax, cin), arr[i]);
        res = std::max(res, max);
    }
    return res;
}

int main()
{

    return 0;
}