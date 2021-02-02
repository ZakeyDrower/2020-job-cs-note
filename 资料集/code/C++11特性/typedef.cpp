#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef int P();
typedef void Q(int *p, const string & s1, const string & s2, size_t size, bool isTrue);

class X {
public :    
    P(eat_shit); // int eat_shit();
    Q(bullshit); // void bullshit(int *p, const string s1, const string & s2, size_t size, bool isTrue)
};

int X::eat_shit() {return 888;}
void X::bullshit(int *p, const string & s1, const string & s2, size_t size, bool isTrue) 
{
    cout << s1 << ",  " << s2 << ",  " << size << endl;
    printf("elems:\n");
    for(int i = 0; i < size; i++) {
        printf("%d %s",  *p++, (i == size-1) ? "" : ",");
    }
    printf("\n");
}

int main() {
    X *xx;
    printf("shit ret: %d\n", xx->eat_shit());
    int a[] = {1, 3, 4, 5, 7};
    xx->bullshit(a, "foo", "bar", sizeof(a)/sizeof(int), true);
}

/**
作者：知乎用户
链接：https://www.zhihu.com/question/29798061/answer/144423125
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/