 ///
 /// @file    mutex.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-21 14:39:20
 ///
 
#include <iostream>
#include <pthread.h>
#include <stdio.h>
using std::cout;
using std::endl;
class Mutex{
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();
	private:
		pthread_mutex_t mutex;
};
inline Mutex::Mutex(){
	pthread_mutex_init(&mutex,NULL);
}
inline Mutex::~Mutex(){
	pthread_mutex_destroy(&mutex);
}
void Mutex::lock(){
	pthread_mutex_lock(&mutex);
}
void Mutex::unlock(){
	pthread_mutex_unlock(&mutex);
}
Mutex mutex;
void * func(void* sum){
	int i = 10000000;
	while(i--){
		mutex.lock();
		*(int *)sum += 1;
		mutex.unlock();
	}
	return (void*)i;
}
int main(){
	int sum = 0;
	pthread_t pthid1,pthid2;
	pthread_create(&pthid1,NULL,func,(void*)&sum);
	pthread_create(&pthid2,NULL,func,(void*)&sum);
	int ret1,ret2;
	pthread_join(pthid1,(void**)&ret1);
	pthread_join(pthid2,(void**)&ret2);
	cout<<"ret1 = "<<ret1<<" "<<"ret2 = "<<ret2<<endl;
	cout<<"sum = "<<sum<<endl;
	return 0;
}
