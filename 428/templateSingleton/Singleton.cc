 ///
 /// @file    Singleton.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-28 12:09:58
 ///
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Student
{
public:
	Student()
	: _id(100)
	, _name("mike")
	{}

	void print()
	{
		cout << _id << "," << _name << endl;
	}
private:
	int _id;
	string _name;
};


template <typename T>
class Singleton{
	public:
		class Release{
			public:
				~Release();
		};
	public:
		static T * getInstance();
	private:
		Singleton();
		~Singleton();
		static T * instance;
		static Release release;
};
template<typename T>
T * Singleton<T>::instance = NULL;
template<typename T>
typename Singleton<T>::Release Singleton<T>::release;
template<typename T>
Singleton<T>::Release::~Release()
{
	if(NULL != instance){
		delete instance;
	}
}
template<typename T>
T * Singleton<T>::getInstance()
{
	if(NULL == instance){
		instance = new T;
	}
	return instance;
}
int main(){
#if 1
	Student * p1 = Singleton<Student>::getInstance();
	Student * p2 = Singleton<Student>::getInstance();
	p1->print();
#endif
	return 0;
}
