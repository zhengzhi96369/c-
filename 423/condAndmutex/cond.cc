 ///
 /// @file    cond.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 19:46:53
 ///
 
#include <iostream>
#include "cond.h"
Cond::Cond(){
	pthread_cond_init(&_cond,NULL);
	pthread_mutex_init(&_mutex,NULL);
}
Cond::~Cond(){
	pthread_mutex_destroy(&_mutex);
	pthread_cond_destroy(&_cond);
}
void Cond::wait(){
	pthread_mutex_lock(&_mutex);
	pthread_cond_wait(&_cond,&_mutex);
	pthread_mutex_unlock(&_mutex);
}
void Cond::notify(){
	pthread_cond_signal(&_cond);
}
void Cond::notifyAll(){
	pthread_cond_broadcast(&_cond);
}
