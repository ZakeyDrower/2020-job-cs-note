#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SmartPoint
{
public:
    int* m_count;
    T* m_ptr;
public:
    SmartPoint();
    SmartPoint(T* ptr_);
    SmartPoint(SmartPoint<T>& ptr_);
    SmartPoint<T>& operator=(SmartPoint<T>&  prt_);
    void Release(); //释放智能指针
    T* GetObjPtr(); //得到指针地址
    void PrintInfo();
    ~SmartPoint();
};


template <typename T>
SmartPoint<T>::SmartPoint()
{
    
}

template <typename T>
SmartPoint<T>::SmartPoint(T* ptr_) : m_ptr(ptr_)
{
    if(ptr_)
    {
        cout << "process ctor..." << endl;
        //int i = 1;
        m_count = new int(1);
    }
    else
    {
        m_ptr = nullptr;
        cout << "指针为空，无法实现只能指针" << endl;
        m_count = 0;
    }
}

template <typename T>
SmartPoint<T>::SmartPoint(SmartPoint<T> & ptr_)
{
    // if(ptr_.m_ptr )
    // {
    //     m_ptr = ptr_.m_ptr;
    //     (*(ptr_.m_count))++;
    //     this->m_count = ptr_.m_count;
    // }
    this->m_ptr = ptr_.m_ptr;
    this->m_count = ptr_.m_count;
    (*m_count)++;
    cout << "copy dtor called!" << endl;
}

template <typename T>
SmartPoint<T>& SmartPoint<T>::operator=(SmartPoint<T>&  ptr_)
{
    if (this != &ptr_)
	{
		delete m_ptr;
		m_ptr = ptr_.m_ptr;
		ptr_.m_ptr = nullptr;
	}
	return *this;
}

template <typename T>
SmartPoint<T>::~SmartPoint()
{
    if (*m_count == 1)
	{
		cout << "---------dtor()-------" << endl;
		delete m_ptr;
        delete m_count;
		m_ptr = nullptr; //置为空
        m_count = nullptr;
        cout << "-----dtor successed!-----" << endl;
	}
	else
	{
        cout << "dtor(): mem not clear!" << endl;
        (*m_count)--;
	}
}

int main()
{
    int a = 100;
    SmartPoint<int> MM((int*)&a);
    cout << *(MM.m_ptr) << " : " << *(MM.m_count) << endl;
	SmartPoint<int> FF(MM);
    cout << *(FF.m_ptr) << " : " << *(FF.m_count) << endl;
    if(true)
    {
        SmartPoint<int> EE(MM);
        a = 5;
        cout << "dtor() will be called!" << endl;
    }
    cout << *(FF.m_ptr) << " : " << *(FF.m_count) << endl;
    cout << "dtor() will be called!" << endl;
    FF.~SmartPoint();
    cout << *(FF.m_ptr) << " : " << *(FF.m_count) << endl;

    system("pause");
	return 0;
}