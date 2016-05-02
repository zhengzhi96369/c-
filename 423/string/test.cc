 ///
 /// @file    test.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-25 01:52:37
 ///
 
#include <iostream>
#include "mystring.h"
using std::cout;
using std::endl;
using std::boolalpha;
using std::cin;
int main(void){
	MyString s1 = "Haha";
	cout<<s1<<endl;
	MyString s2;
	s2 = s1;
	cout<<s2<<endl;
	cout<<"Input a string:"<<endl;
	MyString s3;
	cin>>s3;
	cout<<s3<<endl;
	s3 +=s1;
	cout<<s3<<endl;
	cout<<s3.size()<<endl;
	cout<<"The index 1 of s3 is:"<<s3[1]<<endl;
	s3[1] = 'a';
	cout<<"The index 1 of s3 is:"<<s3[1]<<endl;
	cout<<boolalpha<<(s3 == s3)<<endl;
	cout<<(s3 != s3)<<endl;
	cout<<(s1 < s3)<<endl;
	cout<<(s1 > s3)<<endl;
	cout<<(s1 <= s3)<<endl;
	return 0;
}
