 ///
 /// @file    heapsort.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-05-02 09:53:34
 ///
//堆排序：大根堆的首个元素是最大元素，而从后边拆一个不影响它的性质。
//过程：
//用给定的元素构造一个大根堆，然后从后边开始“拆”
//拆：每次交换最后一个元素和“堆首”，并调整堆，直到第一个元素。
//在这个过程中，每个元素进入堆中，经过深度步就能找到自己的位置（logn的复杂度）。
#include <iostream>
using std::cout;
using std::endl;
bool compare(const int & iref1,const int & iref2)
{
	return iref1 < iref2;
}
//调整堆中pos上的元素，以保持堆的性质
template<typename T>
void heap_adjust(T * data,int num,int pos,bool (*compare)(const T &,const T &)){
	int cur;
	for(;pos < num;)
	{
		cur = pos;
		pos = 2 * pos + 1;
		if(pos < num)
		{
			if(pos + 1 < num && compare(data[pos],data[pos + 1]))
			{
				++pos;
			}
			if(compare(data[cur],data[pos]))
			{
				data[pos] = data[cur] ^ data[pos];
				data[cur] = data[pos] ^ data[cur];
				data[pos] = data[pos] ^ data[cur];
			}else{
				break;
			}
		}else{
			break;
		}
	}
}
template<typename T>
void heap_sort(T *data,int num,bool (*compare)(const T&,const T&))
{
	//construct the array as a heap
	for(int idx = 0;idx != num / 2 - 1;++idx)
	{
		heap_adjust(data,num,idx,compare);
		cout<<"once"<<endl;
	}
	cout<<"construct completed!"<<endl;
	for(int idx = 0;idx != num;++idx)
	{
		cout<<data[idx]<<" ";
	}
	cout<<endl;
	//sort
	for(int idx = num - 1;idx != 0;--idx)
	{
		data[0] = data[idx] ^ data[0];
		data[idx] = data[idx] ^ data[0];
		data[0] = data[idx] ^ data[0];
		heap_adjust(data,idx,0,compare);
		cout<<"one element ready"<<endl;
	}
}
int main(void)
{
	int hehe[10]={7,4,9,6,0,8,1,2,3,5};
	heap_sort(hehe,10,compare);
	for(int idx = 0;idx != 10;++idx)
	{
		cout<<hehe[idx]<<" ";
	}
	cout<<endl;
}
