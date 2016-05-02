 ///
 /// @file    myqueen.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 21:10:51
 ///
#include <string.h>
#include <iostream>
#include "myqueen.h"
MyQueen::MyQueen(){
	_data = new int [MAXSIZE];
	memset(_data,0,sizeof(int)*MAXSIZE);
	_front = 0;//front队首
	_back = -1;//back队尾
}
MyQueen::~MyQueen(){
	delete [] _data;
}
bool MyQueen::empty(){
	return (_front - 1) % MAXSIZE == _back;
}
bool MyQueen::full(){
	return (_back + 2) % MAXSIZE == _front;//必须牺牲掉一个空间来区别满和空	
}
void MyQueen::pop(){
	if(!empty()){
		_data[_front] = 0;
		_front = (_front + 1)%MAXSIZE;
	}else{
		cout<<"Already an empty queen"<<endl;
	}
}
int MyQueen::back(){
	if(!empty()){
		return _data[_back];
	}else{
		cout<<"Empty queen,you'll get 0"<<endl;
		return 0;
	}
}
int MyQueen::front(){
	if(!empty()){
		return _data[_front];
	}else{
		cout<<"Empty queen,you'll get 0"<<endl;
		return 0;
	}
}
void MyQueen::push(int n){
	if(!full()){
		_back = (_back + 1)%MAXSIZE;
		_data[_back] = n;
	}else{
		cout<<"Full queen"<<endl;
	}
}
