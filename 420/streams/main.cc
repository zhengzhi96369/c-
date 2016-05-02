 ///
 /// @file    main.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-20 21:26:29
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string>
#define ALPHANUM 26
//其实用内存映射好啊，何必用流捏
//ifstream fin;//读文件
//ofstream fout;//输出到词典
//istringstream sin;//分词
//ostringstream sout;//控制输出格式
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;
class Word{
public:
	explicit Word(const char *word)
	:freq(1)
	{
		key = new char [strlen(word)+1];
		strcpy(key,word);
	}
	~Word(){
		delete [] key;
	}
	Word(const Word & refw)
	:freq(refw.freq)
	{
		key = new char [strlen(refw.key)+1];
		strcpy(key,refw.key);
	}
	Word & operator = (const Word & refw)
	{
		if(this == &refw){
			return *this;
		}
		delete [] key;
		key = new char [strlen(refw.key)+1];
		strcpy(key,refw.key);
	}
	bool operator == (const Word & refw){
		return 0==strcmp(refw.key,this->key)?true:false;
	}
	void freqAdd(){
		++freq;
	}
	string print2String(){
		ostringstream sout;
		sout<<key<<","<<freq<<endl;
		return sout.str();
	}
private:
	char *key;
	int freq;
};
class WordSet{
public:
	void capacity(int size);
	void addWord(const char *word);
	void out2File(ofstream &fout);
private:
	vector<Word> wvec;
};
void WordSet::addWord(const char *word){
	Word w(word);
	for(int idx = 0;idx != wvec.size();++idx){
		wvec[idx].print2String();
		if(wvec[idx] == w){
			wvec[idx].freqAdd();
			return;
		}
	}
	wvec.push_back(w);
}
void WordSet::capacity(int size){
	wvec.reserve(size);
}
void WordSet::out2File(ofstream &fout){
	if(!fout.good()){
		cout<<"error fout"<<endl;
	}
	for(int idx = 0;idx != wvec.size();++idx){
		fout<<wvec[idx].print2String();
	}
}
//优化：可以考虑以首字母来创建26个子集来提高速度
//在开工之前，给wvec们先根据长度弄个容量
class WordStatic
{
public:
	void readFile(string filename);
	void writeFile(string filename);
private:
	WordSet wset[ALPHANUM+1];//26个词集分别对应a-z
};
void WordStatic::readFile(string filename){
	for(int idx = 0;idx != ALPHANUM;++idx){
		wset[idx].capacity(16);
	}
	ifstream fin(filename.c_str());//c_str是成员函数
	if(!fin.good()){
		cout<<"error path name"<<endl;
		return; 
	}
	string str1;
	string word;
	while(getline(fin,str1)){
		//cout<<str1<<endl;
		istringstream sin(str1);
		int ret;
		while(sin>>word){
			ret = word[0] - 'a';
			if(ret>=0)
			{	
				wset[ret].addWord(word.c_str());
			}else{
				wset[26].addWord(word.c_str());
			}	
		}
	}
	fin.close();
}
void WordStatic::writeFile(string filename){
	ofstream fout(filename.c_str());
	if(!fout.good()){
		cout<<"error path name"<<endl;
		return ;
	}
	for(int idx1 = 0;idx1 != ALPHANUM;++idx1){
		wset[idx1].out2File(fout);
	}
	fout.close();
}
int main(int argc,char *argv[]){
	if(3!=argc){
		cout<<"error args"<<endl;
		return -1;
	}
	WordStatic ws;
	ws.readFile(argv[1]);
	ws.writeFile(argv[2]);
}
