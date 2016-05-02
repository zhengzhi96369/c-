 ///
 /// @file    sigleton.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-21 10:45:34
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
class Singleton{
	public:
		static Singleton * create(){
	//		if(NULL == instance){
	//			instance = new Singleton;
	//		}
			return instance;
		}
		static void destroy(){//外部调用create创建对象，内部new方法是不可见的，因此需要
			//提供destory来保证对应。
			if(NULL == instance)return;
			delete instance;
			instance = NULL;
		}
	private:
		Singleton()
		{
			cout<<"Singleton()"<<endl;
		}
		~Singleton()//静态对象必须手动销毁
		{
			cout<<"~Singleton()"<<endl;
		}	
	public:
		static Singleton * instance;
};
Singleton * Singleton::instance = new Singleton;
//Singleton::instance = NULL;
int main(){
	Singleton *ps1 = Singleton::create();
	Singleton *ps2 = Singleton::create();
	Singleton *ps3 = Singleton::create();
	printf("%p\n",ps1);
	printf("%p\n",ps2);
	printf("%p\n",ps3);
	ps1->destroy();
	Singleton::destroy();
	return 0;
}
