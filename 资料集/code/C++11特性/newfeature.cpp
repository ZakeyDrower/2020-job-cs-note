#include"header.h"
 
// class Person {
// 	private: 
// 		int age;
// 		int size;
// 		string name;
// 	public :
// 		Person(){this.age = 10;};
// 		void func(int a, int s) const
// 		{
// 			this.age = a;
// 		};
// };

int main(void)
{
    // // 右值引用 T&&
    // int&& a = ReturnVal();      // 编译成功
    // int&& b = a;                // 编译失败
    // // 普通引用 T&  需要用const修饰
    // int& a = ReturnVal();       // 编译失败
    // const int& a = ReturnVal(); // 编译成功

    // Base(Base&& base): data(base.data){ base.data = nullptr; }

    // std::is_move_constructible<T>::value;

	//const char cs[10] = "abc";
	try{
		vector<int> v(5);
		cout << v.at(10);
	} catch (const std::exception & e) {
		cout << "Exception : " << e.what() << endl;
	}


    // two shared pointers representing two persons by their name
	// default deleter
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"),
            // deleter (a lambda function) 
            [](string *p)
            { 
                cout << "delete " << *p << endl;
                delete p;
            }
        );
	// user deleter
	shared_ptr<int> p(new int[10], default_delete<int[]>());
	shared_ptr<int> pp(new int[10],
		[](int* a) {
			cout << "delete " << *a << endl;
			delete a;
		});
 
    // capitalize person names
    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");
 
    // put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
 
    // print all elements
    for (auto ptr : whoMadeCoffee)
        cout << *ptr << " ";
    cout << endl;
 
    // overwrite a name again
    *pNico = "Nicolai";
 
    // print all elements
    for (auto ptr : whoMadeCoffee)
        cout << *ptr << " ";
    cout << endl;
 
    // print some internal data
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
 
    return 0;
}