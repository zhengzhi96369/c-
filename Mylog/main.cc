 ///
 /// @file    main.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 12:12:10
 ///
#include <iostream>
#include "mylog.h"
int main(){
	int i = 10;
	while(--i){
		Warn("lala");
		Info("haha");
		Error("gaga");
		Debug("wawa");
	}
	return 0;
}
