#include <bits/stdc++.h>
using namespace std;

class Singleton {
    public :
    static Singleton & getInstance() {
        static Singleton ins;
        return ins;
    }
    void printTest() {
        std::cout << "do something" << std::endl;
    }

    private :
    Singleton () = default; // protect from constructor
    Singleton (const Singleton & ins); // protect from copy construct
    Singleton & operator = (const Singleton & ins); // protect from assignment construct
};

int main()
{
    Singleton & inst = Singleton::getInstance();
    inst.printTest();
    return 0;
}