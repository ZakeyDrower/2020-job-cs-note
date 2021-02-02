#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int ia[6] = { 25, 219, 47, 22, 48, 79} ;
    vector<int, allocator<int>> vec(ia, ia+6);

    cout << count_if(vec.begin(), vec.end(), not1(bind2nd(less<int>(), 40))) << endl;

    return 0;
}