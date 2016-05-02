 ///
 /// @file    stack.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 20:18:31
 ///
#ifndef __MYSTACK_H__
#define __MYSTACK_H__
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 10
class MyStack{
	public:
		MyStack();
		~MyStack();
		void push(int);
		void pop();
		int top();
		bool empty();
		bool full();
	private:
		int * _data;
		int _top;
};
#endif
