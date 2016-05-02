 ///
 /// @file    stack_only.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-20 15:36:32
 ///
 
#include <iostream>
#include <string.h>
#include <stdlib.h>
using std::cout;
using std::endl;
//如果只能在堆空间存在，那么只好让对象的构造函数或者析构函数不能正常工作。
//如此一来，由于new和delete表达式执行流程中涉及到上述二者，因此需要添加相应的类的静态方法提供给他们类的作用域来访问构造或析构函数
//下边写的是二者同时私有化的范例
class Student{
	public:
		Student & operator = (const Student &);
		//void operator = (const Student &);
		void print();
		static void hehe();
		static void * operator new (size_t size){
			cout<<"operator new"<<endl;
			void * p = malloc(size);
			return p;
		}
		static void operator delete (void* p){
			cout<<"operator delelte"<<endl;
			free(p);
		}
		static Student * create(long id,const char * name){//new
			Student * ps = new Student(id,name);
			return ps;
		}
		static Student * create(){
			Student * ps = new Student();
			return ps;
		}
		static void destory(Student * p){
			delete p;
		}
	private:
		long _sid;
		char * _sname;
		static long id_default;
		Student();
		Student(long id,const char * name);
		Student(const Student&);
		~Student();
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
void Student::hehe(){
	cout<<"hehe"<<endl;
};
long Student::id_default = 201613001;
int main(){
	Student *ps1 = Student::create(201614001,"Luo");
	Student *ps2 = Student::create();
	ps1->print();
	ps2->print();
	Student::destory(ps1);
	Student::destory(ps2);
	//Student s2;//cannot define a Student type in the stack
}
