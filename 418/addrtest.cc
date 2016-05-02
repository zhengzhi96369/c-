 ///
 /// @file    addrtest.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-18 20:46:55
 ///
 
#include <iostream>
#include <string.h>
#include <stdio.h>
using std::cout;
using std::endl;
int a = 10;
const int b = 10;
int main(){
	int c = 10;
	char cs[20] = "woshinibaba";
	char *p = "woshinibaba";
	char *pnew = new char [20];
	strcpy(pnew,"woshinibaba");
	static int d = 10;
	printf("%p\n",&a);//全局变量放在全局/静态区（可读可写）
	printf("%p\n",&b);//全局常量放在字符串常量区（只读）
	printf("%p\n",&c);//局部变量放在栈空间中（高地址，向下）
	printf("%p\n",&d);//静态局部变量放在全局/静态区（可读可写）
	printf("%p\n",&cs);//字符数组（c风格字符串）放在栈区
	printf("%p\n",&pnew);//局部指针变量放在栈区
	printf("%p\n",pnew);//堆区空间，一个比较大但不算大的地方
	printf("%p\n",&p);//局部指针变量放在栈区
	printf("%p\n",p);//字符串常量放在字符串常量区（只读）
}
