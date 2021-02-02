#include<bits/stdc++.h>
using namespace std;


void my_per_rec(string s, int l, int r)
{
    if(l == r) {
        cout << s << endl;
        return ;
    }
    for(int i = l; i <= r; ++ i) {
        std::swap(s[i], s[l]);
        my_per_rec(s, l+1, r);
        //std::swap(s[i], s[l]);
    }
}

void my_permutation_rec(string s)
{
    if(s.size() < 2) return;
    my_per_rec(s, 0, s.size()-1);
}

template<typename Itr>
bool my_next_permutation(Itr start, Itr end)
{
    if(start == end)
        return false;
    Itr i = end;
    if(start == end)
        return false;
    
    while(true) {
        Itr i1 = i, i2;
        if(*--i < *i1) {
            i2 = end;
            while(!(*--i2 > *i))
                ;
            iter_swap(i, i2);
            reverse(i1, end);
            return true;
        }
        if(i == start){
            swap(i, end);
            return false;
        }
    }
}

int main()
{
    string s = "123";
    sort(s.begin(), s.end());
    cout <<s;
    while(next_permutation(s.begin(), s.end())) {
        cout << " " << s;
    }

    cout << endl;
    sort(s.begin(), s.end());
    my_permutation_rec(s);

    cout << endl << endl;
    sort(s.begin(), s.end());
    cout <<s;
    while(my_next_permutation(s.begin(), s.end())) {
        cout << " " << s;
    }
    return 0;
}