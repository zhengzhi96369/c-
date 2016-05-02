 ///
 /// @file    complex.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 12:33:05
 ///
 
#include <iostream>
#include <ostream>
#include <istream>
using std::ostream;
using std::istream;
class Complex{
public:
	Complex();
	Complex(const Complex &);
	~Complex();
	Complex & operator = (const Complex &);//最好不要返回void，否则相关的表达式在判断和复合中会出问题（下同）
	Complex & operator += (const Complex &);
	Complex & operator ++ ();//前置++，返回自身就好了
	Complex operator ++ (int);//后置++，先返回后++
	friend Complex operator + (Complex,Complex);
	friend ostream & operator << (ostream & os,Complex & c);
	friend void opreator >> (istream & is,Complex & c);
private:
	int _dreal;
	int _dimag;
};
ostream & operator << (ostream &,Complex &);
istream & operator >> (istream &,Complex &);
Complex operator + (Complex,Complex);
