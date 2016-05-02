 ///
 /// @file    point.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-18 19:20:05
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class Point{
	public:
		/*explicit*/ Point(const char *name=NULL,int x=0,int y=0)//regard as an inline func,and can't be converted 
		:_ix(x)
		,_iy(y)
		{	
			_iname = new char [strlen(name)+1];
			strcpy(_iname,name);
			cout<<"Constructor"<<endl;
		}
		Point(const Point & refp)//copy constructor
		:_ix(refp._ix)
		,_iy(refp._iy) 
		{	
			_iname = new char [strlen(refp._iname)+1];
			strcpy(_iname,refp._iname);
			cout<<"Copy constructor"<<endl;
		}
		~Point()
		{	
			delete [] _iname;
			cout<<"~Point()"<<endl;
		}
		void print();
		void move(int,int);
		float distance(Point);
	private:
		int _ix;
		int _iy;
		char * _iname;
};
inline void Point::print()//its scope is the class Point
{
	cout<<'('<<_ix<<','<<_iy<<')'<<endl;
}
void Point::move(int x,int y){
	_ix+=x;
	_iy+=y;
	this->print();
}
int main(){
	Point p1("1",1,2);
	Point p2;
	p2 = p1;
//	Point p1(3,4);
//	p1.move(2,6);
//	Point p2(p1);
//	Point p3 = p1;
//	cout<<"Begin"<<endl;
//	Point p4 = 1;
//	cout<<"End"<<endl;
//	Point *pp = new Point(p1);
//	delete pp;
//	Point *pps = new Point [3];
//	delete [] pps;
}
