 ///
 /// @file    mystring.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-25 00:12:07
 ///
#include <string.h>
#include <iostream>
#include "mystring.h"
MyString::MyString(){
	_cArray = new char(0);
}
MyString::MyString(const char *cstr){
	_cArray = new char [strlen(cstr)+1];
	strcpy(_cArray,cstr);
}
MyString::MyString(const MyString & ref){
	_cArray = new char [strlen(ref._cArray)+1];
	strcpy(_cArray,ref._cArray);
}
MyString::~MyString(){
	delete [] _cArray;
}
MyString & MyString::operator = (const MyString & ref){
	if(&ref == this){
		return *this;
	}
	delete [] _cArray;
	_cArray = new char [strlen(ref._cArray)+1];
	strcpy(_cArray,ref._cArray);
	return *this;
}
MyString & MyString::operator += (const MyString & ref){
	char * temp = new char [strlen(_cArray)+strlen(ref._cArray)+1];
	strcpy(temp,_cArray);
	strcat(temp,ref._cArray);
	delete [] _cArray;
	_cArray = temp;
	return *this;
}
char & MyString::operator [](int idx){
	return _cArray[idx];
}
const char & MyString::operator [](int idx)const{
	return _cArray[idx];
}
const char * MyString::cstr()const{
	return _cArray;
}
size_t MyString::size()const{
	return (size_t)strlen(_cArray);
}
MyString operator + (const MyString & lref,const MyString &rref){
	char * temp = new char [strlen(lref._cArray)+strlen(rref._cArray)+1];
	strcpy(temp,lref._cArray);
	strcat(temp,rref._cArray);
	MyString s(temp);
	delete [] temp;
	return s;
}
ostream & operator <<(ostream & os,const MyString & s){
	os<<s._cArray;
}
istream & operator >>(istream & is,MyString & s){
	delete [] s._cArray;
	char buf[128];
	memset(buf,0,128);
	is>> buf;
	s._cArray = new char[strlen(buf)+1];
	strcpy(s._cArray,buf);
}
bool operator == (const MyString &lref,const MyString &rref){
	return 0 == strcmp(lref._cArray,rref._cArray);
}
bool operator != (const MyString &lref,const MyString &rref){
	return !0 == strcmp(lref._cArray,rref._cArray);
}
bool operator >= (const MyString &lref,const MyString &rref){
	return 0 <= strcmp(lref._cArray,rref._cArray);
}
bool operator <= (const MyString &lref,const MyString &rref){
	return 0 >= strcmp(lref._cArray,rref._cArray);
}
bool operator > (const MyString &lref,const MyString &rref){
	return 0 < strcmp(lref._cArray,rref._cArray);
}
bool operator < (const MyString &lref,const MyString &rref){
	return 0 > strcmp(lref._cArray,rref._cArray);
}
