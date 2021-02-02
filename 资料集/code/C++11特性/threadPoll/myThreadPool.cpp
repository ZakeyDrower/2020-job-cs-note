// MyThreadPool/MyThreadPool.cpp                                                                                                                                                                  
#include "myThreadPool.h"
bool MyThread::init()
{
    m_thread = (pthread_t*)malloc(sizeof(pthread_t)); //开辟内存
    pthread_create(m_thread, &(pool->m_attr), MyThread::run, pool );
    return true;
}
bool MyThread::join()
{
    pthread_join(*m_thread,NULL);
    if(m_thread != NULL) free(m_thread);
    return true;
}
void* MyThread::run(void* ptr)
{
    MyThreadPool* pool = (MyThreadPool*)ptr;
    pthread_barrier_wait(&(pool->m_barr));
//  printf("start run!\n");
    Worker* task;
    while(1)
    {   
        if( pool->stopFlag && pool->task_vec.empty() )
            break;
//      printf("try:get\n");
        if(pool->getTask(task))
        {   
//          printf("get this task :%x\n", task);
            task->run();
        }   
        else usleep(100000);
    }   
    return NULL;
}
 
bool MyThreadPool::open(const int& num)
{
    pthread_attr_init(&m_attr);
    pthread_mutex_init(&m_lock, NULL);
    pthread_barrier_init(&m_barr, NULL, num+1); //初始化栅栏
    pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_JOINABLE);//设置线程属性为joinable线程
    pthread_attr_setstacksize(&m_attr, 1024000); //设置线程堆栈大小，b
    stopFlag=false;
    m_threads.reserve(num);
    for(int i = 0; i < num; ++i)
    {
        MyThread* p = new MyThread();
        p->pool = this;
        p->init();
        m_threads.push_back(p);
//      printf("open one thread : %x\n", p);
    }
    pthread_barrier_wait(&m_barr);
    pthread_attr_destroy(&m_attr);
    return true;
}
bool MyThreadPool::join()
{
    stopFlag=true;
    for(int i = 0; i < m_threads.size(); ++i)
    {
        m_threads[i]->join();
//      printf("join one thread : %x\n", m_threads[i]);
        delete m_threads[i];
        m_threads[i] = NULL;
    }
    pthread_mutex_destroy(&m_lock);
    pthread_barrier_destroy(&m_barr);
    return true;
}
bool MyThreadPool::getTask(Worker*& task)
{
//  printf("getTask\n");
    pthread_mutex_lock(&m_lock);
    if(!task_vec.empty())
    {
        task = *task_vec.begin();
        task_vec.erase(task_vec.begin());
    }
    else
        task = NULL;
    pthread_mutex_unlock(&m_lock);
//  printf("get %x, size:%d\n",task, task_vec.size());
    return task==NULL ? false : true;
}
bool MyThreadPool::addTask(Worker* task)
{
    pthread_mutex_lock(&m_lock);
    task_vec.push_back(task);
    pthread_mutex_unlock(&m_lock);
//  printf("add %x, size:%d\n",task, task_vec.size());
    return true;
}