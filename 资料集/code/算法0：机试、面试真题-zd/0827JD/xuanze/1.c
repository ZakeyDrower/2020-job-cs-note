#include<stdio.h>
struct p{
    int x;
    int y;
};

int main()
{
    struct p p1[] = {1, 92, 3, 94, 5, 96};
    struct p * ptr1 = p1;
    int x = (sizeof(p1)/5);
    if(x == 3)
        printf("%d %d ", ptr1->x, (ptr1+x-1)->x);
        else
        printf("false");
}