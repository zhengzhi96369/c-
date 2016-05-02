 ///
 /// @file    testmyqueen.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 22:48:19
 ///
 
#include <iostream>
#include "myqueen.h"
using std::cout;
using std::endl;
using std::boolalpha;
int main(void){
	MyQueen q;
	cout<<boolalpha<<"e "<<q.empty()<<endl;
	cout<<"f "<<q.full()<<endl;
	for(int idx = 0;idx != 11;++idx){
		q.push(idx);
		cout<<"back = "<<q.back()<<endl;
		cout<<"front = "<<q.front()<<endl;
	}
	cout<<boolalpha<<"e "<<q.empty()<<endl;
	cout<<"f "<<q.full()<<endl;
	for(int idx = 0;idx != 11;++idx){
		q.pop();
		cout<<"back = "<<q.back()<<endl;
		cout<<"front = "<<q.front()<<endl;
	}
	cout<<boolalpha<<"e "<<q.empty()<<endl;
	cout<<"f "<<q.full()<<endl;
	return 0;
}
