/*
 * ne_recognizer_resource.h
 *
 *  Created on: Nov 18, 2016
 *      Author: parallels
 */

#ifndef NE_TRANS_NE_RECOGNIZER_RESOURCE_H_
#define NE_TRANS_NE_RECOGNIZER_RESOURCE_H_
#include <string>
#include <vector>
#include <boost/regex.hpp>
using std::wstring;
using std::vector;


struct ne_non_trans
{
	uint16_t start;
	uint16_t length;
	uint8_t type;
};

struct ne_date : public ne_non_trans
{
	uint16_t year;
	uint16_t month;
	uint16_t day;
};

enum date_format_index {
	YEAR_IDX = 1, MON_IDX, DAY_IDX
};

enum time_format_index {
	HOUR_IDX = 1, MIN_IDX, SEC_IDX
};

class formatter_traits {
public:
	static const int MAX_FORMAT_CAP = 8;
private:
	boost::wregex pattern_;
	int format_rule_[MAX_FORMAT_CAP];
	int format_rule_len_;
	uint8_t type;
};

class recognizer_traits
{
public:
	recognizer_traits();
	virtual ~recognizer_traits();
	virtual ne_non_trans* do_recognize(wstring& _wstr, int& start)=0;
	vector<formatter_traits> rec_patterns_;
};

class recognizer_date : public recognizer_traits
{
public:
	ne_non_trans* do_recognize(wstring& _wstr, int& start);
};

//class recognizer_time : public recognizer_traits
//{
//
//};

class ne_recognizer_resource {
public:

	ne_recognizer_resource();
	virtual ~ne_recognizer_resource();

	bool load_regexes(const char* _file);
private:
	vector<recognizer_traits> recognizers;

};



#endif /* NE_TRANS_NE_RECOGNIZER_RESOURCE_H_ */
