#include<bits/stdc++.h>
using namespace std;

void init(int a, int * c)
{
    *c = 3;
    a = 2;
    *c += a;
    a += *c;
}

typedef union  {
    long i;
    char j[10];
    int k;
} DATE;

struct data {
    int m;
    DATE n;
    double l;
} test;

DATE maxx;

int main()
{
    int a = 1;
    init(a, &a);
    printf("%d\n\n", a);
    printf("%d\n\n", sizeof(struct data) + sizeof(maxx));

    int array[5] = {7, 8, 3, 2, 6};
    int *p = (int*)(array + 1);
    int *m = (int*)(&array + 1);
    printf("%d %d %d \n\n", *(array+1), *(p+1), *(m-1));
    // *(m-1) 为什么是6

    return 0;
}