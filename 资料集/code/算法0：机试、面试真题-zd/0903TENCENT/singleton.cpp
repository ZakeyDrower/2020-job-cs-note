#include<bits/stdc++.h>
using namespace std;

class Singleton {

public:
    static Singleton* getSingleton()  {
        if(ins == nullptr) {
            ins = new Singleton();
        }
        return ins;
    }

private:
    Singleton();
    static Singleton* ins;
};

Singleton* Singleton::ins = nullptr;
