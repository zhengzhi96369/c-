#ifndef __MYLOG_H__
#define __MYLOG_H__
#include <iostream>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <string>
using std::ostringstream;
using std::string;
#define Warn(msg) warnLog(detail(msg))
#define Info(msg) infoLog(detail(msg))
#define Debug(msg) debugLog(detail(msg))
#define Error(msg) errorLog(detail(msg))
#define detail(msg) string(msg).append(" in file")\
		.append( __FILE__).append(" at ")\
		.append(int2string(__LINE__)).append(": function(")\
		.append(__func__).append(")").c_str()
	//(ostringstream(string(msg)) << "In" << __FILE__ << "at" << __LINE__ << ":function(" << __func__ << ")").str().c_str()
	//流的方法行不通
class Mylog{
		class Release{
			public:
				Release();
				~Release();
		};
	public:
		void warn_log(const char *msg);
		void error_log(const char *msg);
		void debug_log(const char *msg);
		void info_log(const char *msg);
		static Mylog * log;
		static Mylog * openLog();
		static void closeLog();
	private:
		Mylog();
		~Mylog();
		log4cpp::Category * _category;
		static Release release;
};
void warnLog(const char *);
void infoLog(const char *);
void debugLog(const char *);
void errorLog(const char *);
inline string int2string(int num){
	ostringstream oss;
	oss << num;
	return oss.str();
}
#endif
