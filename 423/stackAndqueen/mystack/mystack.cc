 ///
 /// @file    stack.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 20:26:01
 ///
 
#include <iostream>
#include "mystack.h"
using std::cout;
using std::endl;
MyStack::MyStack(){
	_data = new int [10];
	//memset
	//{0}
	for(int idx = 0;idx != 10;++idx){
		_data[idx] = 0;
	}
	_top = -1;//top存放当前的数据位置
}
MyStack::~MyStack(){
	delete [] _data;
}
void MyStack::push(int n){
	if(MAXSIZE - 1 == _top){
		cout<<"Full Stack,Programme runtime error"<<endl;
		exit(-1);
	}
	_data[++_top] = n;
}
void MyStack::pop(){
	if(!empty()){
		_data[_top--] = 0;
	}else{
		cout<<"Empth Stack,No element for pop"<<endl;
	}	
}
int MyStack::top(){
	if(!empty()){
		return _data[_top];
	}else{
		cout<<"Empty Stack,No element for top"<<endl;
	}	
}
bool MyStack::empty(){
	return -1 == _top;
}
bool MyStack::full(){
	return MAXSIZE == _top;
}
