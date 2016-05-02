 ///
 /// @file    stack_only.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-20 15:36:32
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::size_t;
//只有栈的话，不能申请堆空间，可以从破坏new和delete的过程来进行，相比于栈对象，他们需要额外调用void * operator new (size_t t)
//和 void operator delete (void*)
class Student{
	public:
		Student();
		Student(long id,const char * name);
		Student(const Student&);
		~Student();
		Student & operator = (const Student &);
		//void operator = (const Student &);
		void print();
	private:
		long _sid;
		char * _sname;
		static long id_default;
		void * operator new (size_t t);
		void operator delete (void*);
};
inline Student::Student()
:_sid(id_default++)
{
	_sname = new char [1];
}
inline Student::Student(long id,const char * name)
{	
	if(id < id_default){
		_sid = id_default++;
	}else{
		_sid = id;
		id_default = id + 1;
	}
	_sname = new char [strlen(name)+1];
	strcpy(_sname,name);
}
inline Student::Student(const Student & refs)
:_sid(refs._sid)
{
	_sname = new char [strlen(refs._sname)+1];
	strcpy(_sname,refs._sname);
}
inline Student::~Student(){
	delete [] _sname;
}
inline Student & Student::operator = (const Student & refs){
	//自复制
	if(this == &refs){
		return *this;
	}
	//其他情况
	_sid = refs._sid;
	delete [] _sname;
	_sname = new char [strlen(refs._sname)+1];
	strcpy(_sname,refs._sname);
	return *this;
}
//inline void Student::operator = (const Student & refs){
//	//自复制
//	if(this == &refs){
//		return;
//	}
//	//其他情况
//	_sid = refs._sid;
//	delete [] _sname;
//	_sname = new char [strlen(refs._sname)+1];
//	strcpy(_sname,refs._sname);
//}
void Student::print()
{
	cout<<"Id = "<<_sid<<endl;
	cout<<"Name:"<<_sname<<endl;
}
long Student::id_default = 201613001;
int main(){
	Student s2;
	Student s3(201614001,"zhengzhi");
	s3.print();
	s2 = s3;
	s2.print();
	//Student * ps4;
	//ps4 = new Student(1234,"lixiang");//now it can't be initialized in the heap block
	return 0;
}
