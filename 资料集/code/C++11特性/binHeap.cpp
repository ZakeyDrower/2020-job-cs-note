#include<bits/stdc++.h>
using namespace std;

template<typename T>
class MaxPQ
{  
public: 
    MaxPQ(int cap) {
        this->pq = vector<T>(cap+1, 0);
    }

    T getMax();
    void ins(T t);
    T del(); // delete and return max ele in pq

private:
    // storage elements
    vector<T> pq;
    int N = 0; // ele. num of pq

    void swim(int k);
    void sink(int k);

    void exch(int i, int j) {
        T tmp = pq[i];
        pq[i] = pq[j];
        pq[j] = tmp;
    }

    inline int left(int k) {return k*2;}
    inline int right(int k) {return k*2+1;}
    inline int parent(int k) {return k/2;}
};

template<typename T>
void MaxPQ<T>::swim(int k)
{
    while(k > 1 && pq[parent(k)] < pq[k]) {
        exch(parent(k), k);
        k = parent(k);
    }
}

template<typename T>
void MaxPQ<T>::sink(int k)
{
    // int l = left(k), r = right(k);
    // while(k <= N && pq[k] < std::max(pq[l], pq[r])) {
    //     exch(pq[l]>pq[r] ? l : r, k);
    //     k = pq[l]>pq[r] ? l : r;
    // }
    while(left(k) <= N) {
        int elder = right(k)<=N ? (
            pq[left(k)]>pq[right(k)] ? left(k) : right(k)
        ) : (
            left(k)
        );
        if(pq[k] >= pq[elder])
            break;
        exch(elder, k);
        k = elder;
    }
}

template<typename T>
T MaxPQ<T>::getMax() {return pq[1];}

template<typename T>
void MaxPQ<T>::ins(T t) 
{
    pq.push_back(t);
    swim(++N);
}

template<typename T>
T MaxPQ<T>::del()
{
    T me = pq[1];
    exch(1, N--);
    pq.pop_back();
    sink(1);
    return me;
}

int main()
{

    return 0;
}