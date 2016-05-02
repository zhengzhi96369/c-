 ///
 /// @file    Text_deal.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-05-02 19:30:49
 ///
#include <string.h> 
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include "text_deal.h"
using std::string;
using std::map;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::istringstream;
using std::cin;
typedef map<int,int> appearance;
class Text_deal::Text_deal_implt
{
	public:
		void deal(string);
		void search(string);
	private:
		// a vector to load the total text by line
		vector<string> lvec;
		//a map to split the pair <word,appearance>
		map<string,appearance> wmap;
};
void Text_deal::Text_deal_implt::deal(string file)
{
	ifstream fs(file.c_str());
	if(!fs.good())
	{
		cout<<"File not exist!"<<endl;
	}
	char buf[256];
	string sbuf;
	int line = 0;
	while(memset(buf,0,256),fs.getline(buf,256)&&!fs.eof())
	{
		++line;
		lvec.push_back(sbuf = buf);
		istringstream iss(sbuf);
		while(iss>>sbuf)
		{
			++wmap[sbuf][line];
		}
	}
}
void Text_deal::Text_deal_implt::search(string word)
{
	if(wmap.count(word))
	{
		int total = 0;
		for(appearance::iterator it = wmap[word].begin();it !=wmap[word].end();++it)
		{
			cout<<"At line"<<it->first<<" "<<it->second<<" times"<<": "<<endl;
			cout<<lvec[it->first - 1]<<endl;
			total += it->second;
		}
		cout<<"Total "<<total<<" times"<<endl;
	}else{
		cout<<"Not found!"<<endl;
	}
}
void Text_deal::deal()
{
	string sbuf;
	cout<<"Input the file name:"<<endl;
	cin>>sbuf;
	_t->deal(sbuf);
}
void Text_deal::search()
{
	string sbuf;
	cout<<"Input the word:"<<endl;
	cin>>sbuf;
	_t->search(sbuf);
}
Text_deal::Text_deal()
{
	_t = new Text_deal_implt;
}
Text_deal::~Text_deal()
{
	if(NULL != _t)
	{
		delete _t;
	}
}
