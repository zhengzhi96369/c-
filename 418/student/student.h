 ///
 /// @file    student.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-18 22:10:04
 ///
#ifndef __STUDENT_H__
#define __STUDENT_H__
#define CL 3
typedef int Course_t;
class Student{
	public:
		Student(const char*,char,unsigned short,long);
		Student(const Student &);
		~Student();
		void setId(long);
		void setAge(unsigned short);
		void setSex(char);
		void setGrade(int,Course_t);
		void sBasicInfo();
		void sDetailInfo();
	protected:
		int _spotential;
	private:
		char * _sname;
		long _sid;
		unsigned short _sage;
		char _ssex;//f for female,m for male
		int _sgrades[CL];
};
#endif
