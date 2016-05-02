 ///
 /// @file    test.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-28 11:23:17

#include "myqueue"
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
int main(void)
{
	cout<<boolalpha;
	Queue<int , 10> iQ;
	cout<<"Empty:"<<iQ.empty()<<endl;
	int res;
	for(int idx = 0;idx != 10; ++idx)
	{
		cout<<"Push "<<iQ.push(idx)<<endl;
		iQ.front(res);
		cout<<"Front of the queue:"<<res<<endl;
		iQ.back(res);
		cout<<"Back of the queue:"<<res<<endl;
		cout<<"Is full:"<<iQ.full()<<endl;
	}
	cout<<iQ.pop(res)<<res<<endl;
	iQ.front(res);
	cout<<"Front of the queue:"<<res<<endl;
	iQ.back(res);
	cout<<"Back of the queue:"<<res<<endl;
	cout<<"Is full:"<<iQ.full()<<endl;
	return 0;
}
