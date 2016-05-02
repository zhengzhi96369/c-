 ///
 /// @file    cond.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 19:09:58
 ///
#ifndef __COND_H__
#define __COND_H__
#include <pthread.h> 
#include <iostream>
#include <mutex.h>
using std::cout;
using std::endl;
class Cond{
	public:
		Cond();
		~Cond();
		void wait();
		void notify();
		void notifyAll();
	private:
		pthread_mutex_t _mutex;
		pthread_cond_t _cond;
};
#endif
