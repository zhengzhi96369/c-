 ///
 /// @file    main.c
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-18 23:10:13
 ///
 
#include <iostream>
#include <student.h>
using std::cout;
using std::endl;
using std::cin;
int main(){
	Student s1("Zhengzhi",'m',21,201092439);
	//cout<<s1._spotential<<endl;//protected forbidden visit
	//cout<<s1._sname<<endl;//private the same as before
	s1.sBasicInfo();
	s1.sDetailInfo();
	s1.setGrade(100,1);//public 
	s1.setGrade(98,2);
	s1.setGrade(94,3);
	Student s2(s1);
	s2.setId(123456789);
	s2.setAge(15);
	s2.setSex('k');
	s2.sBasicInfo();
	s2.setSex('f');
	s2.sDetailInfo();
	return 0;
}
