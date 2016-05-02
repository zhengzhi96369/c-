 ///
 /// @file    student.c
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-18 22:31:44
 ///
 
#include <iostream>
#include <student.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using std::cout;
using std::endl;
void Student::setId(long id)
{
	_sid=id;
}
void Student::setAge(unsigned short age)
{
	_sage=age;
}
void Student::setSex(char sex){
	if(sex!='f'&&sex!='m'){
		return ;
	}else{
		_ssex=sex;
	}
}
void Student::setGrade(int grade,Course_t course){
	if(course<=CL){
		_sgrades[course-1]=grade;
	}
}
void Student::sBasicInfo(){
	printf("Basic information for this student:%s %ld %s %d\n"
			,_sname,_sid,_ssex=='f'?"female":_ssex=='m'?"male":"Not known",_sage);
}
void Student::sDetailInfo(){
	sBasicInfo();
	for(int index = 0;index < CL;index++){
		cout<<_sgrades[index]<<'\t';
	}
	cout<<endl;
	cout<<"His/Her potential: "<<_spotential<<endl;
}
Student::Student(const char *name,char sex='o',unsigned short age=0,long id=0)
:_sid(id)
,_sage(age)
,_ssex(sex)
{
	_sname = new char [strlen(name)+1];
	strcpy(_sname,name);
	for(int i=0;i<CL;i++){
		_sgrades[i] = 0;
	}
	_spotential = rand()%100;
}
Student::Student(const Student & s)
:_sid(s._sid)
,_sage(s._sage)
,_ssex(s._ssex)
{
	_sname = new char [strlen(s._sname)+1];
	strcpy(_sname,s._sname);
	for(int i=0;i<CL;i++){
		_sgrades[i] = s._sgrades[i];
	}
	_spotential = rand()%100;
}
Student::~Student(){
	delete [] _sname;
}
