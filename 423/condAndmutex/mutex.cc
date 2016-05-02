 ///
 /// @file    mutex.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 19:39:18
 ///
 
#include <iostream>
#include "mutex.h"
Mutex::Mutex(){
	pthread_mutex_init(&_mutex,NULL);
}
Mutex::~Mutex(){
	pthread_mutex_destroy(&_mutex);
}
void Mutex::lock(){
	pthread_mutex_lock(&_mutex);
}
void Mutex::unlock(){
	pthread_mutex_unlock(&_mutex);
}
