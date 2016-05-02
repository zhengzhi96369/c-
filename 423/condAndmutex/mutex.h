 ///
 /// @file    mutex.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-24 19:16:42
 ///
#ifndef __MUTEX_H__
#define __MUTEX_H__
#include <pthread.h>
#include <iostream>
class Mutex{
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();
	private:
		pthread_mutex_t _mutex;
};
#endif
