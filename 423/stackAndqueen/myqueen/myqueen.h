 ///
 /// @file    myqueen.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 21:02:03
 ///
#ifndef __MYQUEEN_H__
#define __MYQUEEN_H__
#include <iostream>
#define MAXSIZE 11
using std::cout;
using std::endl;
class MyQueen{
	public:
		MyQueen();
		~MyQueen();
		void pop();
		void push(int);
		int back();
		int front();
		bool empty();
		bool full();
	private:
		int _front;
		int _back;
		int * _data;
};
#endif
