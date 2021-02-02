// MyThreadPool/MyThreadPool.h                                                                                                                                                                    
#ifndef __MY_THREAD_POOL_H__
#define __MY_THREAD_POOL_H__
#include <cstdio>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include <unistd.h>
using namespace std;
 
class Worker;
class MyThread;
class MyThreadPool;
 
class Worker
{
    public:
        Worker(){};
        virtual ~Worker(){printf("[ERROR] error ~Worker()\n");};
        virtual void run(){printf("[ERROR] error run()\n");};
};
 
class MyThread
{
    public:
        MyThreadPool* pool;
        pthread_t* m_thread;
 
        MyThread():pool(){};
        ~MyThread(){};
        bool init();
        bool join();
        static void* run(void* ptr);
};
 
class MyThreadPool
{
    public:
        vector<MyThread*> m_threads;
        vector<Worker*> task_vec;
        bool stopFlag;
 
        pthread_attr_t m_attr;
        pthread_mutex_t m_lock;
        pthread_barrier_t m_barr;
 
        bool open(const int& num);
        bool join();
        bool getTask(Worker*& task);
        bool addTask(Worker* task);
 
};
 
 
#endif