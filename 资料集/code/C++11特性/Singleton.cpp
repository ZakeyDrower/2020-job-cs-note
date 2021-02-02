#include<bits/stdc++.h>
using namespace std;

class SSingleton {
    private:  
    SSingleton();
    static SSingleton * ins;
    static mutex mu;

    public:  
    static SSingleton* getInstance() {
        if(ins == nullptr) {
            lock_guard<mutex> lg(mu);
            if(ins ==  nullptr) {
                ins = new SSingleton();
            }
        }
        return ins;
    }
};

class Singleton {
private :
    Singleton();
    static Singleton * ins;

public :
    static Singleton* getInstance()  {
        return ins;
    }
};

Singleton* Singleton::ins = new Singleton();

class Singleton2 {
    private : 
    Singleton2();

    public : 
    static Singleton2 * getIns(){
        static Singleton2 instance;
        return &instance;
    }
}
