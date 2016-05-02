 ///
 /// @file    string.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-25 00:02:08
 ///
#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::size_t;
class MyString{
	public:
		MyString();
		MyString(const char *);
		MyString(const MyString &);
		~MyString();
		//赋值操作符
		MyString & operator = (const MyString &);
		MyString & operator += (const MyString &);
		//下标操作符
		char & operator [](int);//非const是可以“写”的，因此不能只写const
		const char & operator [](int)const;
		//与c风格字符串的强转
		//operator ()char* ()const;//why not
		const char * cstr()const;
		//sizeof不可以被重载，因此需要写自己的size函数
		size_t size()const;
		//+操作符
		friend MyString operator + (const MyString &,const MyString &);
		//流
		friend ostream & operator << (ostream &,const MyString &);
		friend istream & operator >> (istream &,MyString &);
		//一系列比较函数，存在const char*到MyString的构造函数
		//因此不用任何形式的重载（可以隐式转换）
		//不适合用成员方式，将会造成参数坑人，cstring没有这些函数的调用
		friend bool operator == (const MyString &,const MyString &);
		friend bool operator > (const MyString &,const MyString &);
		friend bool operator < (const MyString &,const MyString &);
		friend bool operator >= (const MyString &,const MyString &);
		friend bool operator <= (const MyString &,const MyString &);
		friend bool operator != (const MyString &,const MyString &);
	private:
		char * _cArray;
};
#endif
