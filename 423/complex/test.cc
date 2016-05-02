 ///
 /// @file    test.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 17:31:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Test{
	public:
		void operator()(int ,int){
			cout<<"hehe"<<endl;
		};
		//friend void operator()();
};
//void operator()(){
//	cout<<"hehe"<<endl;
//}
int main(void){
	Test t1;
	Test t2;
	t2 = t1;//不会报错，系统自己提供了一个
	Test t3;
	Test ts[10];
	ts[3];//系统提供了一个
	t1(1,2);
}
