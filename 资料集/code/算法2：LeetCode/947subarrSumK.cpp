#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solu1(vector<int> & a, int K){
    if(K == 0 || a.size()==0) return 0;

    vector<int> pre(a);
    int cnt = 0;
    for(int i=1; i<a.size(); i++) pre[i] += pre[i-1];
    for(int i = a.size()-1; i>=0; i--){
        cnt += pre[i]%K==0 ? 1 : 0;
        for(int j = i-1; j>=0; j--){
            cnt += (pre[i]-pre[j])%K==0 ? 1 : 0;
        }
    }
    return cnt;
}

int solu2(vector<int> & a, int k){
    if(a.size() == 0 || k == 0) return 0;

    unordered_map<int,int> map;
    int cnt = 0;
    for(int i=0; i <a.size(); i++){
        a[i] = ((((i==0?0:a[i-1])+a[i]) % k) + k) % k;
        map[a[i]] ++;
    }
    for(auto p: map){
        cnt += (p.second*(p.second-1))/2;
    }
    return cnt;
}

int subarraysDivByK(vector<int>& A, int K) {
    return solu2(A, K);
}

int main()
{
    cout << (-7)%10 << endl << 7 % 10;
    return 0;
}

