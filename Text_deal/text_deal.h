 ///
 /// @file    Test_deal.h
 /// @author  zhengzhi(2251645084@qq.com)
 /// @date    2016-05-02 19:17:17
 ///
#ifndef __TEXT_DEAL__
#define __TEXT_DEAL__
using std::string;
class Text_deal
{
public:
	Text_deal();
	~Text_deal();
	void deal();
	void search();
private:
	class Text_deal_implt;
	Text_deal_implt * _t;
};
#endif
