 //
 /// @file    mylog.cc
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-04-22 23:41:20
 ///
#include "mylog.h"
using std::cout;
Mylog::Release Mylog::release;
Mylog * Mylog::log = NULL;
Mylog::Mylog()
{
	_category = &(log4cpp::Category::getRoot().getInstance("Mylog"));
	//layout for two appender
	log4cpp::PatternLayout * ptl1 = new log4cpp::PatternLayout();
	ptl1->log4cpp::PatternLayout::setConversionPattern("%d:%p %c %x:%m%n");//%p priority
	log4cpp::PatternLayout * ptl2 = new log4cpp::PatternLayout();
	ptl2->log4cpp::PatternLayout::setConversionPattern("%d:%p %c %x:%m%n");

	//two appender
	log4cpp::RollingFileAppender * rfappender = new log4cpp::RollingFileAppender("rfappender","mylog.log",10*1024,1);
	rfappender->setLayout(ptl1);
	log4cpp::OstreamAppender * oappender = new log4cpp::OstreamAppender("oappender",&cout);
	oappender->setLayout(ptl2);
	
	//add them to our category
	Mylog::_category->addAppender(rfappender);
	Mylog::_category->addAppender(oappender);
	Mylog::_category->setPriority(log4cpp::Priority::DEBUG);
}
Mylog * Mylog::openLog(){
	if(NULL == log){
		log = new Mylog;
	}
	return Mylog::log;
}
Mylog::~Mylog(){
	log4cpp::Category::shutdown();
}
void Mylog::closeLog(){//使用日志后请手动关闭
	if(NULL != log){
		delete log;
	}
}
void Mylog::warn_log(const char *msg){
	_category->warn(msg);
}
void Mylog::error_log(const char *msg){
	_category->error(msg);
}
void Mylog::debug_log(const char *msg){
	_category->debug(msg);
}
void Mylog::info_log(const char *msg){
	_category->info(msg);
}
void warnLog(const char *msg){
	Mylog * log = Mylog::openLog();
	log->warn_log(msg);
}
void errorLog(const char *msg){
	Mylog * log = Mylog::openLog();
	log->error_log(msg);
}
void debugLog(const char *msg){
	Mylog * log = Mylog::openLog();
	log->debug_log(msg);
}
void infoLog(const char *msg){
	Mylog * log = Mylog::openLog();
	log->info_log(msg);
}
Mylog::Release::~Release(){
	if(NULL != log){
//		delete log;//不能实现自动关闭的升级，请大神补充
	}
}
Mylog::Release::Release(){
}
