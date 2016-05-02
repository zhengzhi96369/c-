 ///
 /// @file    quicksort.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-05-02 15:37:34
 ///
#include <iostream>
using std::cout;
using std::endl;
//使用上下界方便可以修改成迭代器
void quick_sort(int * data,int begin,int end)
{	
	if(begin >= end)
	{
		return;
	}
	int pos = begin;
	int rpos = end;
	int temp;
	for(;pos != rpos;++pos)//这里一定要考虑到可能有
		//pos移动时退出和rpos移动时退出两种情况
	{
		cout<<"pos = "<<pos<<endl;
		cout<<"rpos = "<<rpos<<endl;
		if(data[pos] > data[begin])//正向找一个大于的
		{
			for(;rpos != pos;--rpos)//反向找一个小于的
			{
				cout<<"pos = "<<pos<<endl;
				cout<<"rpos = "<<rpos<<endl;
				if(data[rpos] < data[begin])//交换
				{	
				//	data[rpos] = data[rpos] ^ data[pos];
				//	data[pos] = data[rpos] ^ data[pos];
				//	data[rpos] = data[rpos] ^ data[pos];
				//	cout<<"swap once"<<endl;
					temp = data[rpos];
					data[rpos] = data[pos];
					data[pos] = temp;
					break;
				}
			}
			if(rpos == pos)
			{
				cout<<"rpos break"<<endl;
				break;//如果是因为已经相等而退出，
				//则需跳出循环
			}
		}
	}
	cout<<"end once,"<<"pos = "<<pos<<endl;
	//此时pos和rpos二者相等，这个位置的元素可能大于
	//也可能小于首元,我们只处理小于的情况
	if(data[begin] < data[pos])
	{
		--pos;
	}
//	data[begin] = data[begin] ^ data[pos];
//	data[pos] = data[begin] ^ data[pos];
//	data[begin] = data[begin] ^ data[pos];
	temp = data[begin];
	data[begin] = data[pos];
	data[pos] = temp;
	quick_sort(data,begin,pos - 1);
	quick_sort(data,pos + 1,end);
}
int main(void)
{
	int hehe[10] = {5,6,3,2,9,7,8,1,4,0};
	quick_sort(hehe,0,9);
	for(int idx = 0;idx != 10;++idx)
	{
		cout<<hehe[idx]<<" ";
	}
	cout<<endl;
}
