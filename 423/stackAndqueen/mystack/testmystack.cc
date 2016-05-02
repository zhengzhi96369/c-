 ///
 /// @file    testmystack.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 20:47:21
 ///
 
#include <iostream>
#include "mystack.h"
using std::cout;
using std::endl;
int main(){
	MyStack s;
	for(int idx = 0;idx != 10;++idx){
		s.push(idx);
	}
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	return 0;
}
