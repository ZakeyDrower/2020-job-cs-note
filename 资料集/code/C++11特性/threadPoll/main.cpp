// main/main.cpp                                                                                                                                                                                  
#include <cstdio>
#include <iostream>
#include "myThreadPool.h"
using namespace std;
class A : public Worker
{
    public:
        int a,b;
        int ret;
        A(){};
        virtual ~A(){};
        virtual void run(){
            //printf("A.run() start, %d %d\n", a,b);
            printf("curr_task : %x | %d %d\n", this,a,b);
            ret = a + b;
            sleep(1);
            //printf("A.run() finish, %d\n", ret);
        };  
};
 
int main(int argc,char **argv)
{
    MyThreadPool pool;
    pool.open(3);
    for(int i = 0 ; i < 8 ;i ++) 
    {   
        A *a = new A();
        a->a = i;
        a->b = 10; 
        pool.addTask(a);
        //printf("add task!, %d\n", i);
    }   
    pool.join();
    return 0;
}